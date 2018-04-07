package FullAdder;
	function Bit#(2) fa(Bit#(1) a, Bit#(1) b, Bit#(1) c_in);
		Bit#(1) s = (a ^ b) ^ c_in;
		Bit#(1) c_out = (a & b) | (a ^ b) & c_out;
		return {c_out, s};
	endfunction;
	
	Bit#(1) a = 1;
	Bit#(1) b = 0;
	Bit#(1) c_in = 1;

	(* synthesize *)
	module mkFullAdder;
		rule add_bits;
			Bit#(2) sum = fa(a, b, c_in);
			$display(sum);
			$finish(0);
		endrule;
	endmodule;
endpackage;	
