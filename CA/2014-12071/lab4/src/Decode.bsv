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
	halt:
	begin
		dInst.iType = Hlt;
		dInst.opqFunc = FNop;
		dInst.condUsed = Al;
		dInst.valP = pc + 1;
		dInst.dstE = Invalid;
		dInst.dstM = Invalid;
		dInst.regA = Invalid;
		dInst.regB = Invalid;
		dInst.valC = Invalid;
	end

    nop:
    begin
        dInst.iType = Nop;
        dInst.opqFunc = FNop;
        dInst.condUsed = Al;
        dInst.valP = pc + 1;
        dInst.dstE = Invalid;
        dInst.dstM = Invalid;
        dInst.regA = Invalid;
        dInst.regB = Invalid;
        dInst.valC = Valid(imm);
    end

    cmov:
    begin
        dInst.iType = Cmov;
        dInst.opqFunc = FNop;
        dInst.condUsed = case (ifun)
                            fNcnd: Al;
							fLe: Le;
							fLt: Lt;
							fEq: Eq;
							fNeq: Neq;
							fGe: Ge;
							fGt: Gt;
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
		dInst.valP = pc + 2;
		dInst.dstE = validReg(rB);
		dInst.dstM = Invalid;
		dInst.regA = validReg(rA);
		dInst.valC = Invalid;
    end

    rmmovq:
    begin

    end

    mrmovq:
    begin

    end

    opq:
    begin
			dInst.iType = Opq;
			dInst.opqFunc = case(ifun)
												addc: FAdd;
												subc: FSub;
												andc: FAnd;
												xorc: FXor;
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

    end

    call:
    begin

    end

    ret:
    begin

    end

    pushq:
    begin

    end

    popq:
    begin

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
