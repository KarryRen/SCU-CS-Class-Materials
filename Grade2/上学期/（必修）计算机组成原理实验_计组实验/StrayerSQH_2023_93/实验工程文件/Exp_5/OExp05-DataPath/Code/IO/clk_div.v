`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:19:38 07/17/2012 
// Design Name: 
// Module Name:    clk_div 
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
`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:19:38 07/17/2012 
// Design Name: 
// Module Name:    clk_div 
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
module  clk_div(input clk200P,clk200N,
					input rst,
					input STEP,
					output reg[31:0]clkdiv,
					output reg clk100MHz,
					output Clk_CPU
					);
					
	IBUFDS sclk(.I(clk200P), 			//clk: differential clock to signel ended clock
					.IB(clk200N),
					.O(clk200m) 			// this is what we use
					);

// Clock divider-Ê±ÖÓ·ÖÆµÆ÷
	always @ (posedge clk200m)
		clk100MHz <= ~clk100MHz;
		
	assign Clk_CPU =(STEP)? clkdiv[24] : clkdiv[1];

	always @ (posedge clk100MHz or posedge rst) begin 
		if (rst) clkdiv <= 0; 
		else clkdiv <= clkdiv + 1'b1; 
	end
			
endmodule
