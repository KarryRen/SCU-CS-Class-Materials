`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:22:33 02/03/2016
// Design Name:   MUX2T1_5
// Module Name:   D:/FPGA_work/SWORD-ORG/OExp01-MUX/Code/MUX2T1_5_Test.v
// Project Name:  OExp01-MUX
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: MUX2T1_5
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module MUX2T1_5_Test;

	// Inputs
	reg [4:0] I0;
	reg [4:0] I1;
	reg s;

	// Outputs
	wire [4:0] o;

	// Instantiate the Unit Under Test (UUT)
	MUX2T1_5 uut (
		.I0(I0), 
		.I1(I1), 
		.s(s), 
		.o(o)
	);

	initial begin
		// Initialize Inputs
		I0 = 0;
		I1 = 0;
		s = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

