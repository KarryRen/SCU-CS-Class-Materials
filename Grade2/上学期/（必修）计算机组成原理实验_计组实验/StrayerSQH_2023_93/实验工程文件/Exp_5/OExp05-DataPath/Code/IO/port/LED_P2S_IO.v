`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:16:41 03/11/2015 
// Design Name: 
// Module Name:    parallel2serial 
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
module  	  LEDP2S(input wire clk,		//parallel to serial
						input wire rst,
						input wire Start,
						input wire[15:0] PData,
						output wire sclk,
						output wire sclrn,
						output wire sout,
						output reg  EN
						);

parameter
	DATA_BITS = 16,  											// data length
	DATA_COUNT_BITS = 4, 									// data shift bits
	DIR = 0;														// Shift direction

		
endmodule
