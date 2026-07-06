`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:34:44 03/12/2012 
// Design Name: 
// Module Name:    Regs 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////

module Regs(input clk,
				input rst,
				input [4:0] R_addr_A, 
				input [4:0] R_addr_B, 
				input [4:0] Wt_addr, 
				input [31:0]Wt_data, 
				input L_S, 
				output [31:0] rdata_A, 
				output [31:0] rdata_B
			  );

reg [31:0] register [1:31]; 				// r1 - r31
integer i;

	assign rdata_A = (R_addr_A == 0)? 0 : register[R_addr_A]; 	 // read
	assign rdata_B = (R_addr_B == 0)? 0 : register[R_addr_B];    // read
	
	always @(posedge clk or posedge rst) 
      begin
		if (rst==1) 	 begin 			// reset
		    for (i=1; i<32; i=i+1)
		    register[i] <= 0;	//i;
		end 
		else begin
		     if ((Wt_addr != 0) && (L_S == 1)) 	// write
		     register[Wt_addr] <= Wt_data;
		end
	end
endmodule


