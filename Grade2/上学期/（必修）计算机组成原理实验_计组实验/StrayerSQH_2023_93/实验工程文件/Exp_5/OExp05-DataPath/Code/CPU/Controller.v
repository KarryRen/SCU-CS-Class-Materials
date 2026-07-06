`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:12:36 05/26/2014 
// Design Name: 
// Module Name:    SCPU_ctrl 
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
module 	  SCtrl( input[5:0]OPcode,						//OPcode
					   input[5:0]Fun,							//Function						
						input MIO_ready,						//CPU Wait
						
						output reg RegDst,
						output reg ALUSrc_B,
						output reg MemtoReg,
						output reg Jump,
						output reg Branch,
						output reg RegWrite,
						output reg mem_w,
						output reg [2:0]ALU_Control,
						output reg CPU_MIO
					  );

endmodule

