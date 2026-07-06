`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:24:20 02/26/2014 
// Design Name: 
// Module Name:    add_32 
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
module ADC32(input [31:0] A, 
				 input [31:0] B, 
				 input  C0,
				 output [31:0] S,
				 output Co
				  );
				  
//wire B_Notation;

//			wire B_Notation = C0 ^ 1'b0;	  
//			assign {Co,S} = {1'b0,A} + {B_Notation,B} + C0;		//Unsigned
//			assign {Co,S} = {A[31],A} + {B[31],B} + C0;			//sign
			assign {Co,S} = A + B + C0;								//sign

endmodule
