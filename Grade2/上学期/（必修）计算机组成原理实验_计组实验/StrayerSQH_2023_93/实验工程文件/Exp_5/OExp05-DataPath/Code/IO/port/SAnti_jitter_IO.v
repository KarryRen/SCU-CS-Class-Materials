`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:03:38 04/29/2014 
// Design Name: 
// Module Name:    Anti_jitter 
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
module SAnti_jitter(input wire clk, 
								 input wire RSTN,
								 input wire readn,
								 input wire [3:0]Key_y,
								 output reg[4:0] Key_x,
								 input wire[15:0]SW, 
								 output reg[4:0] Key_out,
								 output reg      Key_ready,
								 output reg[3:0] pulse_out,
								 output reg[3:0] BTN_OK,
								 output reg[15:0]SW_OK,
								 output reg 	  CR,
								 output reg 	  rst
								);
	 
endmodule
