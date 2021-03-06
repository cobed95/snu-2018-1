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
	Addr pc;
    Addr ppc;
	Bool epoch;
} Decode2Exec deriving(Bits, Eq);

typedef struct {
    Maybe#(ExecInst) inst;
	Addr pc;
	Bool epoch;
} Exec2Mem deriving(Bits, Eq);

typedef struct {
    Maybe#(ExecInst) inst;
	Addr pc;
	Bool epoch;
} Mem2Write deriving(Bits, Eq);

(*synthesize*)
module mkProc(Proc);
	Reg#(Addr)    pc  <- mkRegU;
	RFile         rf  <- mkBypassRFile;
	IMemory     iMem  <- mkIMemory;
	DMemory     dMem  <- mkDMemory;
	Cop          cop  <- mkCop;

	Reg#(CondFlag) 	 	condFlag	<- mkRegU;
	Reg#(ProcStatus)   	stat		<- mkRegU;

	Fifo#(1, Addr)       execRedirect <- mkBypassFifo;
	Fifo#(1, ProcStatus) statRedirect <- mkBypassFifo;

	Fifo#(2, Fetch2Decode)	f2d     <- mkPipelineFifo;
    Fifo#(2, Decode2Exec)   d2e     <- mkPipelineFifo;
    Fifo#(2, Exec2Mem)      e2m     <- mkPipelineFifo;
    Fifo#(2, Mem2Write)     m2w     <- mkPipelineFifo;

	Reg#(Bool) fEpoch <- mkRegU;
	Reg#(Bool) eEpoch <- mkRegU;

	Scoreboard#(4) sb <- mkPipelineScoreboard;

	/* TODO: Lab 6-1: Implement 5-stage pipelined processor, using given scoreboard.
			 Lab 6-2: Implement 5-stage pipelined processor, using bypassing. */

	rule doFetch(cop.started && stat == AOK);
		/* Fetch */
		Addr realPc;
		Bool iEpoch;
		if(execRedirect.notEmpty)
		begin
			fEpoch <= !fEpoch;
			execRedirect.deq;
			realPc = execRedirect.first;
			iEpoch = !fEpoch;
		end
		
		else
		begin	
			realPc = pc;	
			iEpoch = fEpoch;
		end

		let inst = iMem.req(realPc);
		let ppc = nextAddr(realPc, getICode(inst));
		$display("Fetch : from Pc %d , expanded inst : %x, \n", realPc, inst, showInst(inst));
		pc <= ppc;
		f2d.enq(Fetch2Decode{inst:inst, pc:realPc, ppc:ppc, epoch:iEpoch});
	endrule

	rule doDecode(cop.started && stat == AOK);
		let inst   = f2d.first.inst;
		let ipc    = f2d.first.pc;
		let ppc    = f2d.first.ppc;
		let iEpoch = f2d.first.epoch;

		/* Decode */
		let dInst = decode(inst, ipc);

        let stall = (isValid(dInst.regA) && sb.search1(dInst.regA)) || (isValid(dInst.regB) && sb.search2(dInst.regB));
        if(!stall) 
        begin
            dInst.valA   = isValid(dInst.regA)? tagged Valid rf.rdA(validRegValue(dInst.regA)) : Invalid;
			dInst.valB   = isValid(dInst.regB)? tagged Valid rf.rdB(validRegValue(dInst.regB)) : Invalid;
			dInst.copVal = isValid(dInst.regA)? tagged Valid cop.rd(validRegValue(dInst.regA)) : Invalid;
            
			$display("Decode : from Pc %d , expanded inst : %x, \n", ipc, inst, showInst(inst));

			d2e.enq(Decode2Exec{inst:dInst, pc:ipc, ppc:ppc, epoch:iEpoch});
			sb.insertE(dInst.dstE);
			sb.insertM(dInst.dstM);
			f2d.deq;
        end
		else
			$display("STALLING for pc: %d. \n", ipc, showInst(inst));
    endrule

    rule doExec(cop.started && stat == AOK);
		if(!d2e.notEmpty)
			$display("d2e empty.");
        let dInst = d2e.first.inst;
        let ppc = d2e.first.ppc;
        let iEpoch = d2e.first.epoch;
		let ipc = d2e.first.pc;
		
        if(iEpoch == eEpoch)
		begin
			/* Execute */
			let eInst = exec(dInst, condFlag, ppc);
			condFlag <= eInst.condFlag;
			$display("Executed %d", ipc);	

			if(eInst.mispredict)
			begin
				eEpoch <= !eEpoch;
				/* if(eInst.iType != Ret)
				begin
					let redirPc = validValue(eInst.nextPc);
					$display("mispredicted, redirect %d ", redirPc);
					execRedirect.enq(redirPc);
					eInst.mispredict = !eInst.mispredict;
				end */
			end 
			
			e2m.enq(Exec2Mem{inst:Valid(eInst), pc:ipc, epoch:iEpoch});
			d2e.deq;
        end
			
		else
		begin
			e2m.enq(Exec2Mem{inst:Invalid, pc:ipc, epoch:iEpoch});
			$display("Not Executed because epoch is different: %d ", ipc);
			d2e.deq;
		end
    endrule

    rule doMem(cop.started && stat == AOK);
		let iEpoch = e2m.first.epoch;
		let ipc = e2m.first.pc;
		
		if(isValid(e2m.first.inst))
		begin		
			let eInst = validValue(e2m.first.inst);
		    
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
				let redirPc = validValue(eInst.nextPc);
				$display("mispredicted, redirect %d ", redirPc);
				execRedirect.enq(redirPc);
			end
		    
			$display("Mem done with pc: %d", ipc);

			m2w.enq(Mem2Write{inst:Valid(eInst), pc:ipc, epoch:iEpoch});
			e2m.deq;
		end
			
		else
		begin
			m2w.enq(Mem2Write{inst:Invalid, pc:ipc, epoch:iEpoch});
			$display("Mem cancelled with pc: %d", ipc);
			e2m.deq;
		end
    endrule

    rule doWrite(cop.started && stat == AOK);
		let iEpoch = m2w.first.epoch;
		let ipc = m2w.first.pc;
		
		if(isValid(m2w.first.inst))
		begin		
			let eInst = validValue(m2w.first.inst);
        
			/* WriteBack */
			if(isValid(eInst.dstE))
			begin
				$display("On %d, writes %d   (wrE)", validRegValue(eInst.dstE), validValue(eInst.valE));
				rf.wrE(validRegValue(eInst.dstE), validValue(eInst.valE));
				$display("wrE with %d: ", ipc);
			end
			if(isValid(eInst.dstM))
			begin
				$display("On %d, writes %d   (wrM)", validRegValue(eInst.dstM), validValue(eInst.valM));
				rf.wrM(validRegValue(eInst.dstM), validValue(eInst.valM));
				$display("wrM with $d: ", ipc);
			end

			cop.wr(eInst.dstE, validValue(eInst.valE));
        
			/* Update Status */
			let newStatus = case(eInst.iType)
								Unsupported : INS;
								Hlt 		  : HLT;
								default     : AOK;
							endcase;
			statRedirect.enq(newStatus);	
			
			m2w.deq;
			$display("wrote with pc: %d", ipc);
			sb.remove;
			$display("removed an item from scoreboard.");
		end	

		else
		begin
			m2w.deq;
			$display("did not write with pc: %d", ipc);
			sb.remove;
			$display("removed an item from scoreboard.");
		end
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
