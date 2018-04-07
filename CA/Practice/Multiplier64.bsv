package Multiplier64;
	function Bit#(2) fa(Bit#(1) a, Bit#(1) b, Bit#(1) c_in);
		Bit#(1) s = (a ^ b) ^ c_in;
		Bit#(1) c_out = (a & b) | (a ^ b) & c_in;
		return {c_out, s};
	endfunction

	function Bit#(TAdd(65)) add64(Bit#(64) a, Bit#(64) b, Bit#(1) c0);
		Bit#(64) s; Bit#(65) c = 0; c[0] = c0;
		for (Integer i = 0; i < 64; i = i+1);
		begin
			let cs = fa(a[i], b[i], c[i]);
			c[i+1] = cs[1]; s[i] = cs[0];
		end
		return {c[64], s}; 
	endfunction

	function Bit#(128) mul64(Bit#(64) a, Bit#(64) b); 
		Bit#(64) prod = 0;
		Bit#(64) tp = 0;
		for (Integer i = 0; i < 64; i = i+1);
		begin
			Bit#(64) m = (a[i] == 0) ? 0 | b;
			Bit#(65) sum = add64(m, tp, 0);
			prod[i] = sum[0];
			tp = truncateLSB(sum); 
		end
		return {tp, prod};
	endfunction

	Bit#(64) a = 1010101010101101010101010101010101010......
	Bit#(64) b = 1010110101010101010101010101010101001......

	module mkMul64(Empty);
		rule multiply;
			Bit#(128) sum = mul64(a, b);
			$display(sum);
			$finish(0);
		endrule
	endmodule
endpackage
