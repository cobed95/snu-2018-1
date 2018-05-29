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

typedef struct {
	Maybe#(FullIndx) rIndx;
	Maybe#(Data) data;
} Bypassed deriving(Bits, Eq);

typedef struct {
	IType iType;
	Maybe#(FullIndx) dstM;
} LoadUseTrigger deriving(Bits, Eq);

function Bool stall(DecodedInst dInst, LoadUseTrigger trigger);
    return (trigger.iType == MRmov || trigger.iType == Pop)  
				&& (trigger.dstM == dInst.regA || trigger.dstM == dInst.regB);
endfunction

function DecodedInst forward(DecodedInst dInst, 
					Fifo#(1, Bypassed) e2d, 
					Fifo#(1, Bypassed) m2dE, 
					Fifo#(1, Bypassed) m2dM, 
					Fifo#(1, Bypassed) w2dE, 
					Fifo#(1, Bypassed) w2dM);
	
    DecodedInst forwarded = dInst;
	if(e2d.notEmpty && e2d.first.rIndx == dInst.regA)
		forwarded.valA = e2d.first.data;	
	else if(m2dE.notEmpty && m2dE.first.rIndx == dInst.regA)
		forwarded.valA = m2dE.first.data;
	else if(m2dM.notEmpty && m2dM.first.rIndx == dInst.regA)
		forwarded.valA = m2dM.first.data;
	else if(w2dE.notEmpty && w2dE.first.rIndx == dInst.regA)
        forwarded.valA = w2dE.first.data;
    else if(w2dM.notEmpty && w2dM.first.rIndx == dInst.regA)
        forwarded.valA = w2dM.first.data;

	if(e2d.notEmpty && e2d.first.rIndx == dInst.regB)
		forwarded.valB = e2d.first.data;
	else if(m2dE.notEmpty && m2dE.first.rIndx == dInst.regB)
		forwarded.valB = m2dE.first.data;
	else if(m2dM.notEmpty && m2dM.first.rIndx == dInst.regB)
		forwarded.valB = m2dM.first.data;
	else if(w2dE.notEmpty && w2dE.first.rIndx == dInst.regB)
		forwarded.valB = w2dE.first.data;
	else if(w2dM.notEmpty && w2dM.first.rIndx == dInst.regB)
		forwarded.valB = w2dM.first.data;
	
    return forwarded;
endfunction

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

	Fifo#(1, Bypassed)		e2d		<- mkBypassFifo;
	Fifo#(1, Bypassed)		m2dE	<- mkBypassFifo;
	Fifo#(1, Bypassed)		m2dM	<- mkBypassFifo;
	Fifo#(1, Bypassed)		w2dE	<- mkBypassFifo;
	Fifo#(1, Bypassed)		w2dM	<- mkBypassFifo;

	Fifo#(1, LoadUseTrigger) trig	<- mkBypassFifo;

	Reg#(Bool) fEpoch <- mkRegU;
	Reg#(Bool) eEpoch <- mkRegU;

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
		$display("Decode : from Pc %d , expanded inst : %x, \n", ipc, inst, showInst(inst));
        
        if(trig.notEmpty && stall(dInst, trig.first))
        begin
            dInst.iType = Nop;
		    dInst.condUsed = Al;
		    dInst.valP = pc + 1;
	        dInst.dstE = Invalid;
		    dInst.dstM = Invalid;
		    dInst.regA = Invalid;
		    dInst.regB = Invalid;
		    dInst.valC = Invalid;

			d2e.enq(Decode2Exec{inst:dInst, pc:ipc, ppc:ppc, epoch:iEpoch});
			$display("Stalling for load-use DH");
        end
        
        else
        begin
            dInst.valA   = isValid(dInst.regA)? tagged Valid rf.rdA(validRegValue(dInst.regA)) : Invalid;
			dInst.valB   = isValid(dInst.regB)? tagged Valid rf.rdB(validRegValue(dInst.regB)) : Invalid;
			dInst.copVal = isValid(dInst.regA)? tagged Valid cop.rd(validRegValue(dInst.regA)) : Invalid;

            DecodedInst newDInst = forward(dInst, e2d, m2dE, m2dM, w2dE, w2dM);

			if(dInst != newDInst)
			begin
				dInst = newDInst;	
				$display("Decoded using forwarded data. srcA, srcB: %d, %d", validValue(dInst.valA), validValue(dInst.valB));
			end

			 
			d2e.enq(Decode2Exec{inst:dInst, pc:ipc, ppc:ppc, epoch:iEpoch});
			f2d.deq;
        end
		
		if(trig.notEmpty)
			trig.deq;
		if(e2d.notEmpty)
			e2d.deq;
		if(m2dE.notEmpty)
			m2dE.deq;
		if(m2dM.notEmpty)
			m2dM.deq;
		if(w2dE.notEmpty)
			w2dE.deq;
		if(w2dM.notEmpty)
			w2dM.deq;

    endrule

    rule doExec(cop.started && stat == AOK);
        let dInst = d2e.first.inst;
        let ppc = d2e.first.ppc;
        let iEpoch = d2e.first.epoch;
		let ipc = d2e.first.pc;
		
        if(iEpoch == eEpoch)
		begin
			/* Execute */
			let eInst = exec(dInst, condFlag, ppc);
            e2d.enq(Bypassed{rIndx:eInst.dstE, data:eInst.valE});
			condFlag <= eInst.condFlag;
			$display("Executed %d", ipc);	
			
			let iType = eInst.iType;
			case(iType) MRmov, Pop :
				begin
					$display("Detected stall trigger at Exec stage with pc: %d", ipc);
					trig.enq(LoadUseTrigger{iType:iType, dstM:eInst.dstM});
				end	
			endcase

			if(eInst.mispredict)
			begin
				eEpoch <= !eEpoch;	
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
            m2dE.enq(Bypassed{rIndx:eInst.dstE, data:eInst.valE});
		    
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

            m2dM.enq(Bypassed{rIndx:eInst.dstM, data:eInst.valM});
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
            w2dE.enq(Bypassed{rIndx:eInst.dstE, data:eInst.valE});
            w2dM.enq(Bypassed{rIndx:eInst.dstM, data:eInst.valM});
        
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
		end	

		else
		begin
			m2w.deq;
			$display("did not write with pc: %d", ipc);
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
