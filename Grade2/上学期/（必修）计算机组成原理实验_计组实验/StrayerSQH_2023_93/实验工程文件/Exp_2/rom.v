`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:18:04 11/21/2024 
// Design Name: 
// Module Name:    rom 
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
module rom( 
        input addr, 
        output [63:0] dout 
    ); 
        reg [63:0] data[1:0]; 
        initial begin 
           data[0] = 64'hF8829299_B0A4F9C0; 
           data[1] = 64'h8E86A1C6_83889080; 
        end 
        assign dout = data[addr];
    endmodule


