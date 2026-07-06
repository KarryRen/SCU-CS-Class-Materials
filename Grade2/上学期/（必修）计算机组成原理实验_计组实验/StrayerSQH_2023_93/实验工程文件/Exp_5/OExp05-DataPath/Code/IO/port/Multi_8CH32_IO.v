`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:50:10 11/03/2014 
// Design Name: 
// Module Name:    Output_2_Disp 
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
module 		Multi_8CH32(input clk,
								input rst,
								input EN,								//Write EN
								input[2:0]Test,						//ALU&Clock,SW[7:5]	
								input[63:0]point_in,					//针对8位显示输入各8个小数点
								input[63:0]LES,					//针对8位显示输入各8个闪烁位
								input[31:0] Data0,					//disp_cpudata
								input[31:0] data1,
								input[31:0] data2,
								input[31:0] data3,
								input[31:0] data4,
								input[31:0] data5,
								input[31:0] data6,
								input[31:0] data7,
								output [7:0] point_out,
								output [7:0] LE_out,
								output [31:0]Disp_num
								);
									
	
endmodule


