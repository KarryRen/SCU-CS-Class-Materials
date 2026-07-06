`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:22:03 01/01/2006 
// Design Name: 
// Module Name:    adder_4bit 
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
module adder_4bits( 
      input [size-1 : 0] a, 
      input [size-1 : 0] b, 
      input ci, // carry input 
      output [size-1 : 0] s, // sum 
      output co 
      ); 
    parameter size = 4; 
    wire [2:0] ct; // carry temp 
    adder_1bit a1(.a(a[0]), .b(b[0]), .ci(ci), .s(s[0]),.co(ct[0])), 
    a2(.a(a[1]), .b(b[1]), .ci(ct[0]), .s(s[1]),.co(ct[1])), 
    a3(.a(a[2]), .b(b[2]), .ci(ct[1]), .s(s[2]),.co(ct[2])), 
    a4(.a(a[3]), .b(b[3]), .ci(ct[2]), .s(s[3]),.co(co)); 
endmodule

