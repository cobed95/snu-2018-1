import Types::*;
import ProcTypes::*;
import Vector::*;


function DecodedInst decode(Inst inst,Addr pc);
	DecodedInst dInst = ?;
	let iCode = inst[79:76];
	let ifun  = inst[75:72];
	let rA    = inst[71:68];
	let rB    = inst[67:64];
	let imm   = little2BigEndian(inst[63:0]);
	let dest  = little2BigEndian(inst[71:8]);

	case (iCode)

	/* TODO: Finish implementing decode.bsv */
	/* HINT: rrmovq is included in cmov */
	halt, nop:
	begin
		dInst.iType = case (iCode)
                        begin
                            halt: Hlt;
                            nop: Nop;
                        end
		dInst.opqFunc = FNop;
		dInst.condUsed = Al;
		dInst.valP = pc + 1;
		dInst.dstE = Invalid;
		dInst.dstM = Invalid;
		dInst.regA = Invalid;
		dInst.regB = Invalid;
		dInst.valC = Invalid;
	end

    cmov:
    begin
        dInst.iType = Cmov;
        dInst.opqFunc = FNop;
        dInst.condUsed = case (ifun)
                        begin
                            fNcnd: Al;
							fLe: Le;
							fLt: Lt;
							fEq: Eq;
							fNeq: Neq;
							fGe: Ge;
							fGt: Gt;
                        end
        dInst.valP = pc + 2;
		dInst.dstE = validReg(rB);
		dInst.dstM = Invalid;
		dInst.regA = validReg(rA);
		dInst.regB = Invalid;
		dInst.valC = Invalid;
    end

    irmovq:
    begin
		dInst.iType = Rmovq;
		dInst.opqFunc = FNop;
		dInst.condUsed = Al;
		dInst.valP = pc + 10;
		dInst.dstE = validReg(rB);
		dInst.dstM = Invalid;
		dInst.regA = Invalid;
        dInst.regB = Invalid;
		dInst.valC = Valid(imm);
    end

    rmmovq:
    begin 
        dInst.iType = RMmovq;
        dInst.opqFunc = FAdd;
        dInst.condUsed = Al;
        dInst.valP = pc + 10;
        dInst.dstE = Invalid;
        dInst.dstM = Invalid;
        dInst.regA = validReg(rA);
        dInst.regB = validReg(rB);
        dInst.valC = Valid(imm);
    end

    mrmovq:
    begin
        dInst.iType = MRmovq;
        dInst.opqFunc = FAdd;
        dInst.condUsed = Al;
        dInst.valP = pc + 10;
        dInst.dstE = Invalid;
        dInst.dstM = validReg(rA);
        dInst.regA = Invalid;
        dInst.regB = validReg(rB);
        dInst.valC = Valid(imm);
    end

    opq:
    begin
		dInst.iType = Opq;
		dInst.opqFunc = case(ifun)
                        begin
							addc: FAdd;
							subc: FSub;
							andc: FAnd;
							xorc: FXor;
                        end
		dInst.condUsed = Al;
		dInst.valP = pc + 2;
		dInst.dstE = validReg(rB);
		dInst.dstM = Invalid;
		dInst.regA = validReg(rA);
		dInst.regB = validReg(rB);
		dInst.valC = Invalid;
    end

    jmp:
    begin
        dInst.iType = Jmp;
        dInst.opqFunc = FNop;
        dInst.condUsed = case(ifun)
                        begin
                            fNcnd: Al;
							fLe: Le;
							fLt: Lt;
							fEq: Eq;
							fNeq: Neq;
							fGe: Ge;
							fGt: Gt;
                        end
        dInst.valP = pc + 9;
        dInst.dstE = Invalid;
        dInst.dstM = Invalid;
        dInst.regA = Invalid;
        dInst.regB = Invalid;
        dInst.valC = Valid(dest);
    end

    call, ret:
    begin
        case(iCode)
            call:
            begin
                dInst.iType = Call; 
                dInst.opqFunc = FSub;
                dInst.valP = pc + 9;
                dInst.valC = Valid(dest);
                dInst.regA = Invalid;
            end
            ret:
            begin
                dInst.iType = Ret;
                dInst.opqFunc = FAdd;
                dInst.valP = pc + 1;
                dInst.valC = Invalid;
                dInst.regA = validReg(rsp);
            end
        dInst.condUsed = Al;
        dInst.dstE = validReg(rsp);
        dInst.dstM = Invalid;
        dInst.regB = validReg(rsp);
    end

    pushq:
    begin
        dInst.iType = Push;
        dInst.opqFunc = FSub;
        dInst.condUsed = Al;
        dInst.valP = pc + 2;
        dInst.dstE = validReg(rsp);
        dInst.dstM = Invalid;
        dInst.regA = validReg(rA);
        dInst.regB = validReg(rsp);
        dInst.valC = Invalid;
    end

    popq:
    begin
        dInst.iType = (rA == rsp)? Unsupported : Pop;
        dInst.opqFunc = FAdd;
        dInst.condUsed = Al;
        dInst.valP = pc + 2;
        dInst.dstE = validReg(rsp);
        dInst.dstM = validReg(rA);
        dInst.regA = validReg(rsp);
        dInst.regB = validReg(rsp);
        dInst.valC = Invalid;
    end

	/* DO NOT MODIFY BELOW HERE! */
	copinst:
	begin
		dInst.iType = case(ifun)
					  	mtc0 : Mtc0; //Mtc0
					  	mfc0 : Mfc0; //Mfc0
				  	  endcase;
		dInst.opqFunc = FNop;
		dInst.condUsed = Al;
		dInst.valP = pc + 2;
		dInst.dstE = case(ifun)
						mtc0 : validCop(rB);
						mfc0 : validReg(rB);
					 endcase;
		dInst.dstM = Invalid;
		dInst.regA = case(ifun)
						mtc0 : validReg(rA);
						mfc0 : validCop(rA);
					 endcase;
		dInst.regB = Invalid;
		dInst.valC = Invalid;
	end

	default:
	begin
		dInst.iType = Unsupported;
		dInst.opqFunc = FNop;
		dInst.condUsed = Al;
		dInst.valP = pc + 1;
		dInst.dstE = Invalid;
		dInst.dstM = Invalid;
		dInst.regA = Invalid;
		dInst.regB = Invalid;
		dInst.valC = Invalid;
	end

	endcase
	return dInst;
endfunction
