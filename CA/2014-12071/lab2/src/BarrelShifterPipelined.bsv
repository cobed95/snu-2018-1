import Multiplexer::*;
import FIFO::*;
import FIFOF::*;
import Vector::*;
import SpecialFIFOs::*;

/* Interface of the basic right shifter module */
interface BarrelShifterRightPipelined;
	method Action shift_request(Bit#(64) operand, Bit#(6) shamt, Bit#(1) val);
	method ActionValue#(Bit#(64)) shift_response();
endinterface

module mkBarrelShifterRightPipelined(BarrelShifterRightPipelined);
	let inFifo <- mkFIFOF;
	let outFifo <- mkFIFOF;
	FIFOF#(Tuple3#(Bit#(64), Bit#(6), Bit#(1))) fifo0 <- mkFIFOF;
	FIFOF#(Tuple3#(Bit#(64), Bit#(6), Bit#(1))) fifo1 <- mkFIFOF;
	FIFOF#(Tuple3#(Bit#(64), Bit#(6), Bit#(1))) fifo2 <- mkFIFOF;
	FIFOF#(Tuple3#(Bit#(64), Bit#(6), Bit#(1))) fifo3 <- mkFIFOF;
	FIFOF#(Tuple3#(Bit#(64), Bit#(6), Bit#(1))) fifo4 <- mkFIFOF;
	
	rule shift0;
		Tuple3#(Bit#(64), Bit#(6), Bit#(1)) received = inFifo.first();
		inFifo.deq();
		Bit#(64) operand = tpl_1(received); Bit#(6) shamt = tpl_2(received); Bit#(1) val = tpl_3(received);
		for (Integer i = 0; i < 64; i = i + 1)
			if (i + 1 < 64)
				operand[i] = multiplexer1(shamt[0], operand[i], operand[i+1]);
			else
				operand[i] = multiplexer1(shamt[0], operand[i], val);
		fifo0.enq(tuple3(operand, shamt, val));
	endrule
	
	rule shift1;
		Tuple3#(Bit#(64), Bit#(6), Bit#(1)) received = fifo0.first();
		fifo0.deq();
		Bit#(64) operand = tpl_1(received); Bit#(6) shamt = tpl_2(received); Bit#(1) val = tpl_3(received);
		for (Integer i = 0; i < 64; i = i + 1)
			if (i + 2 < 64)
				operand[i] = multiplexer1(shamt[1], operand[i], operand[i+2]);
			else
				operand[i] = multiplexer1(shamt[1], operand[i], val);
		fifo1.enq(tuple3(operand, shamt, val));
	endrule
	
	rule shift2;
		Tuple3#(Bit#(64), Bit#(6), Bit#(1)) received = fifo1.first();
		fifo1.deq();
		Bit#(64) operand = tpl_1(received); Bit#(6) shamt = tpl_2(received); Bit#(1) val = tpl_3(received);
		for (Integer i = 0; i < 64; i = i + 1)
			if (i + 4 < 64)
				operand[i] = multiplexer1(shamt[2], operand[i], operand[i+4]);
			else
				operand[i] = multiplexer1(shamt[2], operand[i], val);
		fifo2.enq(tuple3(operand, shamt, val));
	endrule

	rule shift3;
		Tuple3#(Bit#(64), Bit#(6), Bit#(1)) received = fifo2.first();
		fifo2.deq();
		Bit#(64) operand = tpl_1(received); Bit#(6) shamt = tpl_2(received); Bit#(1) val = tpl_3(received);
		for (Integer i = 0; i < 64; i = i + 1)
			if (i + 8 < 64)
				operand[i] = multiplexer1(shamt[3], operand[i], operand[i+8]);
			else
				operand[i] = multiplexer1(shamt[3], operand[i], val);
		fifo3.enq(tuple3(operand, shamt, val));
	endrule
	
	rule shift4;
		Tuple3#(Bit#(64), Bit#(6), Bit#(1)) received = fifo3.first();
		fifo3.deq();
		Bit#(64) operand = tpl_1(received); Bit#(6) shamt = tpl_2(received); Bit#(1) val = tpl_3(received);
		for (Integer i = 0; i < 64; i = i + 1) 
			if (i + 16 < 64)
				operand[i] = multiplexer1(shamt[4], operand[i], operand[i+16]);
			else 
				operand[i] = multiplexer1(shamt[4], operand[i], val);
		fifo4.enq(tuple3(operand, shamt, val));
	endrule

	rule shift5;
		Tuple3#(Bit#(64), Bit#(6), Bit#(1)) received = fifo4.first();
		fifo4.deq();
		Bit#(64) operand = tpl_1(received); Bit#(6) shamt = tpl_2(received); Bit#(1) val = tpl_3(received);
		for (Integer i = 0; i < 64; i = i + 1)
			if (i + 32 < 64)
				operand[i] = multiplexer1(shamt[5], operand[i], operand[i+32]);
			else
				operand[i] = multiplexer1(shamt[5], operand[i], val);
		outFifo.enq(operand);
	endrule

	method Action shift_request(Bit#(64) operand, Bit#(6) shamt, Bit#(1) val);
		inFifo.enq(tuple3(operand, shamt, val));
	endmethod

	method ActionValue#(Bit#(64)) shift_response();
		outFifo.deq();
		return outFifo.first();
	endmethod
endmodule


/* Interface of the three shifter modules
 *
 * They have the same interface.
 * So, we just copy it using typedef declarations.
 */
interface BarrelShifterRightLogicalPipelined;
	method Action shift_request(Bit#(64) operand, Bit#(6) shamt);
	method ActionValue#(Bit#(64)) shift_response();
endinterface

typedef BarrelShifterRightLogicalPipelined BarrelShifterRightArithmeticPipelined;
typedef BarrelShifterRightLogicalPipelined BarrelShifterLeftPipelined;

module mkBarrelShifterLeftPipelined(BarrelShifterLeftPipelined);
	/* TODO: Implement left shifter using the pipelined right shifter. */
	let bsrp <- mkBarrelShifterRightPipelined;
	
	method Action shift_request(Bit#(64) operand, Bit#(6) shamt);
		operand = reverseBits(operand);
		bsrp.shift_request(operand, shamt, 0);
	endmethod

	method ActionValue#(Bit#(64)) shift_response();
		let result <- bsrp.shift_response();
		result = reverseBits(result);
		return result;
	endmethod
endmodule

module mkBarrelShifterRightLogicalPipelined(BarrelShifterRightLogicalPipelined);
	/* TODO: Implement right logical shifter using the pipelined right shifter. */
	let bsrp <- mkBarrelShifterRightPipelined;

	method Action shift_request(Bit#(64) operand, Bit#(6) shamt);
		bsrp.shift_request(operand, shamt, 0);
	endmethod

	method ActionValue#(Bit#(64)) shift_response();
		let result <- bsrp.shift_response();
		return result;
	endmethod
endmodule

module mkBarrelShifterRightArithmeticPipelined(BarrelShifterRightArithmeticPipelined);
	/* TODO: Implement right arithmetic shifter using the pipelined right shifter. */
	let bsrp <- mkBarrelShifterRightPipelined;

	method Action shift_request(Bit#(64) operand, Bit#(6) shamt);
		bsrp.shift_request(operand, shamt, operand[63]);
	endmethod

	method ActionValue#(Bit#(64)) shift_response();
		let result <- bsrp.shift_response();
		return result;
	endmethod
endmodule
