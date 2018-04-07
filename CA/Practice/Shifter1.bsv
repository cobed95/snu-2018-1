package Shifter1;
	function Bit#(2) shift1(Bit#(2) a, Bit#(1) s);
		Bit#(2) shifted = (s == 0) {0, a[1]} : a;
		return shifted;
	endfunction

	module mkShifter1(Empty);
		rule shift;
			Bit#(2) shifted = shift1(a, s);
			$display(shifted);
			$finish(0);
		endrule
	endmodule
endpackage
