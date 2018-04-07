package WBitRCAdder;
	function Bit#(2) fa(Bit#(1) x, Bit#(1) y, Bit#(1), c_in);
		Bit#(1) s = (a ^ b) ^ c_in;
		Bit#(1) c_out = (a & b) | (a ^ b) & c_in;
		return {c_out, s};
	endfunction

	function Bit#(TAdd(w+1)) addN(Bit#(w) x, Bit#(w) y, Bit#(1) c0); 
		Bit#(w) s; Bit#(TAdd(w+1)) c = 0; c[0] = c0;
		let valw = valueOf(w);
		for (Integer i = 0; i < valw; i = i+1);
		begin
			let cs = fa(x[i], y[i], c[i]);
			c[i+1] = cs[1]; s[i] = cs[0];
		end
		return {c[valw], s};
	endfunction

	module mkAdder(Empty); 
		rule addBits;
			Bit#(TAdd(w+1)) sum = addN(x, y, c0); 
			$display(sum);
			$finish(0);
		endrule
	endmodule
endpackage
