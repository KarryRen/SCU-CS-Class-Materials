`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:58:11 07/01/2012 
// Design Name: 
// Module Name:    Device_led 
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
module 		 GPIO(input clk,
						input rst,
						input Start,
						input EN,
						input [31:0] P_Data,
						output reg[1:0] counter_set,
						output [15:0] LED_out,
						output wire ledclk,
						output wire ledsout,
						output wire ledclrn,
						output wire LEDEN,
						output reg[13:0] GPIOf0						 
						);

reg [15:0]LED;
// GPIO out use on LEDs & Counter-Controler read and write
	assign LED_out = LED;
	always @(negedge clk or posedge rst) begin
		if(rst)begin LED <= 8'h2A; counter_set<=2'b00; end
		else if(EN)  {GPIOf0[13:0],LED,counter_set} <= P_Data;	//Counter ch1 ch0
			  else begin LED <= LED; counter_set<=counter_set; end
	end	
	
	LEDP2S	#(.DATA_BITS(16),.DATA_COUNT_BITS(4),.DIR(0)) 
						  PTLED (.clk(clk),
									.rst(rst),
									.Start(Start),
									.PData(LED),								//SWORD-V2 LEDµÍÓÐÐ§
									.sclk(ledclk),
									.sclrn(ledclrn),
									.sout(ledsout),
									.EN(LEDEN)
									);					
	
/*	#(.DATA_BITS(16),.DATA_COUNT_BITS(4)) 
				LED_P2S(clk, rst, Start,
						 {{LED[0],LED[1],LED[2],LED[3],LED[4],LED[5],LED[6],LED[7],
						  LED[8],LED[9],LED[10],LED[11],LED[12],LED[13],LED[14],LED[15]}},
								ledclk,
								ledclrn,
								ledsout,
								LEDEN
							 );
*/
endmodule
