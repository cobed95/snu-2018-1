package ShifterN;
	function Bit#(2) shift1(Bit#(2) a, Bit#(1) s); 
		
	endfunction

	function Bit#(TAdd(n + n)) shiftN(Bit#(n) a, Bit#(1) s);
		Bit(TAdd(n + n)) shifted = 0;
		let valn = valueOf(n);
		for (Integer i = valn-1; i >= 0; i = i-1);
		begin
			s
		end	
	endfunction
endpackage
