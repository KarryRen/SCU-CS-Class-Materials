// Verilog test fixture created from schematic C:\Documents and Settings\muxSQH\mux2t1_4.sch - Thu Nov 21 09:53:55 2024

`timescale 1ns / 1ps

module mux2t1_4_mux2t1_4_sch_tb();

// Inputs
   reg [3:0] b;
   reg sel;
   reg [3:0] a;

// Output
   wire [3:0] o;

// Bidirs

// Instantiate the UUT
   mux2t1_4 UUT (
		.b(b), 
		.sel(sel), 
		.a(a), 
		.o(o)
   );
// Initialize Inputs
   initial begin 
a = 0; 
b = 0; 
sel = 0; 
#100; 
a = 4'b1010; 
b = 4'b0001; 
sel = 0; 
#100; 
sel = 1; 
end

endmodule
