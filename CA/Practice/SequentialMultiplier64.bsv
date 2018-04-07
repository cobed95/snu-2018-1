package SequentialMultiplier64;
	function Bit#(2) fa(Bit#(1) a, Bit#(1) b, Bit#(1) c_in);
		Bit#(1) s = (a ^ b) ^ c;
		Bit#(1) c_out = (a & b) | (a ^ b) & c;
		return {c_out, s};
	endfunction

	function Bit#(65) add64(Bit#(64) a, Bit#(64) b, Bit#(1) c0);
		Bit#(64) s; Bit#(65) c = 0; c[0] = c0;
		for (Integer i = 0; i < 64; i = i + 1);
		begin
			let cs = fa(a[i], b[i], c[i]);
			c[i+1] = cs[1]; s[i] = cs[0];
		end
		return {c[64], s};
	endfunction

	module mkSeqMul64(Empty);
		Reg#(64) a <- mkRegU();
		Reg#(64) b <- mkRegU();
		Reg#(64) prod <- mkRegU();
		Reg#(64) tp <- mkRegU();
		Reg#(7) i <- mkReg(64);

		rule mulStep (i < 64);
			Bit#(64) m = (a[i] == 0) ? 0 : b;
			Bit#(65) sum = add64(m, tp, 0);
			prod[0] <= sum[0];
			tp <= sum[64:1];
			i <= i + 1;
		endrule
	endmodule
endpackage
