interface Multiply;
	method Action start(Bit#(64) ain, Bit#(64) bin);
	method Bit#(128) result();
endinterface

module mkMul64(Multiply);
	Reg#(Bit#(64)) a <- mkRegU();
	Reg#(Bit#(64)) b <- mkRegU();
	Reg#(Bit#(64)) tp <- mkRegU();
	Reg#(Bit#(64)) prod <- mkRegU();
	Reg#(Bit#(7)) i <- mkReg(64);

	rule mulStep(i < 64);
		Bit#(64) m = (a[0] == 0) ? 0 : b;
		Bit#(65) sum = add64(m, tp, 0);
		tp <= sum[64:1]; prod <= {sum[0], (prod >> 1)[62:0]}; a <= a >> 1;
		i <= i + 1;
	endrule

	method Action start(Bit#(64) ain, Bit#(64) bin) if (i == 64);
		a <= ain; b <= bin; tp <= 0; prod <= 0; i <= 0;
	endmethod

	method Bit#(128) result() if (i == 64);
		return {tp, prod};
	endmethod
endmodule
