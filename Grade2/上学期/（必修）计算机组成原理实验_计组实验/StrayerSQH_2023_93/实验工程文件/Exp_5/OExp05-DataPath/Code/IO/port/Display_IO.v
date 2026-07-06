`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:28:50 12/29/2015 
// Design Name: 
// Module Name:    Display_IO 
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
module    Display(input clk,			//	时钟
						input rst,			//复位
						input Start,		//串行扫描启动
						input Text,			//文本(16进制)/图型(点阵)切换
						input flash,		//七段码闪烁频率
						input[31:0]Hexs,	//32位待显示输入数据
						input[7:0]points,	//七段码小数点：8个
						input[7:0]LES,		//七段码使能：=1时闪烁
						
						output segclk,		//串行移位时钟
						output segsout,	//七段显示数据(串行输出)
						output SEGEN,		//七段码显示刷新使能
						output segclrn		//七段码显示汪零
						);

endmodule
