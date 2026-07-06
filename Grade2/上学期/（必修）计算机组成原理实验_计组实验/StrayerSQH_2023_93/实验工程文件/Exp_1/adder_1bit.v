`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:20:10 01/01/2006 
// Design Name: 
// Module Name:    adder_1bit 
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
module adder_1bit( 
      input a, 
      input b, 
      input ci, 
      output s, 
      output co 
      ); 
    wire s1, c1, c2, c3; 
    and (c1, a, b), (c2, b, ci), (c3, a, ci); 
    xor (s1, a, b), (s, s1, ci); 
    or (co, c1, c2, c3); 
endmodule

