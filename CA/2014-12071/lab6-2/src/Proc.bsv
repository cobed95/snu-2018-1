import Types::*;
import ProcTypes::*;
import MemTypes::*;
import BypassRFile::*;
import Scoreboard::*;
import IMemory::*;
import DMemory::*;
import Decode::*;
import Exec::*;
import Cop::*;
import Fifo::*;

typedef struct {
	Inst inst;
	Addr pc;
	Addr ppc;
	Bool epoch;
} Fetch2Decode deriving(Bits, Eq);

typedef struct {
	DecodedInst inst;
    Addr ppc;
	Bool epoch;
} Decode2Exec deriving(Bits, Eq);

typedef struct {
    Maybe#(ExecInst) inst;
	Bool epoch;
} Exec2Mem deriving(Bits, Eq);

typedef struct {
    Maybe#(ExecInst) inst;
} Mem2Write deriving(Bits, Eq);

typedef struct {
	Maybe#(FullIndx) rIndx;
	Maybe#(Data)	  data;
} Exec2Decode deriving(Bits, Eq);

typedef struct {
	Maybe#(FullIndx) rIndx;
	Maybe#(Data)	  data;
} Mem2Decode deriving(Bits, Eq);

(*synthesize*)
module mkProc(Proc);
	Reg#(Addr)    pc  <- mkRegU;
	RFile         rf  <- mkBypassRFile;
	IMemory     iMem  <- mkIMemory;
	DMemory     dMem  <- mkDMemory;
	Cop          cop  <- mkCop;

	Reg#(CondFlag) 	 	condFlag	<- mkRegU;
	Reg#(ProcStatus)   	stat		<- mkRegU;

	Fifo#(1, Exec2Decode)	e2d		<- mkBypassFifo;
	Fifo#(1, Mem2Decode)	m2d		<- mkBypassFifo;

	Fifo#(1, Addr)       execRedirect <- mkBypassFifo;
	Fifo#(1, ProcStatus) statRedirect <- mkBypassFifo;

	Fifo#(2, Fetch2Decode)	f2d     <- mkPipelineFifo;
    Fifo#(2, Decode2Exec)   d2e     <- mkPipelineFifo;
    Fifo#(2, Exec2Mem)      e2m     <- mkPipelineFifo;
    Fifo#(2, Mem2Write)     m2w     <- mkPipelineFifo;

	Reg#(Bool) fEpoch <- mkRegU;
	Reg#(Bool) eEpoch <- mkRegU;
    Reg#(Bool) stall <- mkReg(False);

	/* Scoreboard#(4) sb <- mkPipelineScoreboard; */

	/* TODO: Lab 6-1: Implement 5-stage pipelined processor, using given scoreboard.
			 Lab 6-2: Implement 5-stage pipelined processor, using bypassing. */

	rule doFetch(cop.started && stat == AOK);
		/* Fetch */
		if(execRedirect.notEmpty)
		begin
			fEpoch <= !fEpoch;
			execRedirect.deq;
			pc <= execRedirect.first;
		end
		else
		begin
			let inst = iMem.req(pc);
			let ppc = nextAddr(pc, getICode(inst));

			$display("Fetch : from Pc %d , expanded inst : %x, \n", pc, inst, showInst(inst));
			pc <= ppc;
			f2d.enq(Fetch2Decode{inst:inst, pc:pc, ppc:ppc, epoch:fEpoch});
		end
	endrule

	rule doDecode(cop.started && stat == AOK);
		let inst   = f2d.first.inst;
		let ipc    = f2d.first.pc;
		let ppc    = f2d.first.ppc;
		let iEpoch = f2d.first.epoch;

		/* Decode */
		let dInst = decode(inst, ipc);

        if(dInst.iType == MRmov)
            stall <= True;
        if(stall)
            stall <= !stall;
        else
        begin
		    if(e2d.notEmpty || m2d.notEmpty) 
		    begin
			    if(e2d.notEmpty && m2d.notEmpty)
                begin
                    let bypassed = e2d.first;                
                    e2d.deq;
                    m2d.deq;
                end

			    else if(e2d.notEmpty)
                begin
                    let bypassed = e2d.first;
                    e2d.deq;
                end

                else if(m2d.notEmpty)
                begin
                    let bypassed = m2d.first;
                    m2d.deq;
                end
                 
                if(isValid(dInst.regA) && validRegValue(dInst.regA) == validRegValue(bypassed.rIndx))
                    dInst.valA = bypassed.data;
                if(isValid(dInst.regB) && validRegValue(dInst.regB) == validRegValue(bypassed.rIndx))
                    dInst.valB = bypassed.data;
		    end
        
            else
            begin
                dInst.valA   = isValid(dInst.regA)? tagged Valid rf.rdA(validRegValue(dInst.regA)) : Invalid;
		        dInst.valB   = isValid(dInst.regB)? tagged Valid rf.rdB(validRegValue(dInst.regB)) : Invalid;
            end
		    dInst.copVal = isValid(dInst.regA)? tagged Valid cop.rd(validRegValue(dInst.regA)) : Invalid;
            
		    $display("Decode : from Pc %d , expanded inst : %x, \n", ipc, inst, showInst(inst));

		    d2e.enq(Decode2Exec{inst:dInst, ppc:ppc, epoch:iEpoch});
		    f2d.deq;
        end
    endrule

    rule doExec(cop.started && stat == AOK);
        let dInst = d2e.first.inst;
        let ppc = d2e.first.ppc;
        let iEpoch = d2e.first.epoch;

        if(iEpoch == eEpoch)
		begin
			/* Execute */
			let eInst = exec(dInst, condFlag, ppc);
			condFlag <= eInst.condFlag;
			$display("Execute.");
			
            if(isValid(eInst.dstE))
            begin
				e2d.enq(Exec2Decode{rIndx : eInst.dstE, data : eInst.valE});
            end

            e2m.enq(Exec2Mem{inst : Valid(eInst), epoch:iEpoch});	
        end
			
		else
			e2m.enq(Exec2Mem{inst : Invalid, epoch:iEpoch});
		d2e.deq;
    endrule

    rule doMem(cop.started && stat == AOK);
		let iEpoch = e2m.first.epoch;
		if (isValid(e2m.first.inst) && iEpoch == eEpoch)
		begin
			let eInst = validValue(e2m.first.inst);
            if(isValid(eInst.dstE))
                e2d.enq(Exec2Decode{rIndx : eInst.dstE, data : eInst.valE});
		    
			/* Memory */ 
		    let iType = eInst.iType;
		    case(iType)
			    MRmov, Pop, Ret :
			    begin
			        let ldData <- (dMem.req(MemReq{op: Ld, addr: eInst.memAddr, data:?}));
				    eInst.valM = Valid(little2BigEndian(ldData));
				    $display("Loaded %d from %d", little2BigEndian(ldData), eInst.memAddr);
				    if(iType == Ret)
				    begin
					    eInst.nextPc = eInst.valM;	
				    end
                    if(iType == MRmov)
                    begin
						m2d.enq(Mem2Decode{rIndx : eInst.dstM, data : eInst.valM});
                    end
			    end

			    RMmov, Call, Push :
			    begin
				    let stData = (iType == Call)? eInst.valP : validValue(eInst.valA);
				    let dummy <- dMem.req(MemReq{op: St, addr: eInst.memAddr, data: big2LittleEndian(stData)});
				    $display("Stored %d into %d", stData, eInst.memAddr);
			    end
		    endcase
			
			if(eInst.mispredict)
			begin
				eEpoch <= !eEpoch;
				let redirPc = validValue(eInst.nextPc);
				$display("mispredicted, redirect %d ", redirPc);
				execRedirect.enq(redirPc);
			end
		    
			m2w.enq(Mem2Write{inst : Valid(eInst)});
        end
		
		else
			m2w.enq(Mem2Write{inst : Invalid});
		e2m.deq;
    endrule

    rule doWrite(cop.started && stat == AOK);
		if (isValid(m2w.first.inst))
		begin
			let eInst = validValue(m2w.first.inst);
        
			/* WriteBack */
			if(isValid(eInst.dstE))
			begin
				$display("On %d, writes %d   (wrE)", validRegValue(eInst.dstE), validValue(eInst.valE));
				rf.wrE(validRegValue(eInst.dstE), validValue(eInst.valE));
			end
			if(isValid(eInst.dstM))
			begin
				$display("On %d, writes %d   (wrM)", validRegValue(eInst.dstM), validValue(eInst.valM));
				rf.wrM(validRegValue(eInst.dstM), validValue(eInst.valM));
			end

			cop.wr(eInst.dstE, validValue(eInst.valE));
        
			/* Update Status */
			let newStatus = case(eInst.iType)
								Unsupported : INS;
								Hlt 		  : HLT;
								default     : AOK;
							endcase;
			statRedirect.enq(newStatus);
		end
		m2w.deq;
		/*sb.remove;*/
    endrule

	rule upd_Stat(cop.started);
		$display("Stat update");
		statRedirect.deq;
		stat <= statRedirect.first;
	endrule

	rule statHLT(cop.started && stat == HLT);
		$fwrite(stderr, "Program Finished by halt\n");
		$finish;
	endrule

	rule statINS(cop.started && stat == INS);
		$fwrite(stderr, "Executed unsupported instruction. Exiting\n");
		$finish;
	endrule

	method ActionValue#(Tuple3#(RIndx, Data, Data)) cpuToHost;
		let retV <- cop.cpuToHost;
		return retV;
	endmethod

	method Action hostToCpu(Addr startpc) if (!cop.started);
		cop.start;
		eEpoch <= False;
		fEpoch <= False;
		pc <= startpc;
		stat <= AOK;
	endmethod
endmodule
