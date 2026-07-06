// Verilog test fixture created from schematic C:\Documents and Settings\muxSQH\mux2t1.sch - Sun Jan 01 01:42:53 2006

`timescale 1ns / 1ps

module mux2t1_mux2t1_sch_tb();

// Inputs
   reg a;
   reg b;
   reg sel;

// Output
   wire o;

// Bidirs

// Instantiate the UUT
   mux2t1 UUT (
		.a(a), 
		.b(b), 
		.sel(sel), 
		.o(o)
   );
// Initialize Inputs
   initial begin 
a = 0; 
b = 0; 
sel = 0; 
#100; 
a = 1; 
b = 0; 
sel = 0; 
#100; 
a = 0; 
b = 1; 
sel = 1; 
end

endmodule
