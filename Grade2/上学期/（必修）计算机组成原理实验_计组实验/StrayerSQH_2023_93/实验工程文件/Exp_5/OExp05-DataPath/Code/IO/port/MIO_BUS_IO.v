`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:04:14 06/30/2012 
// Design Name: 
// Module Name:    MIO_BUS 
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
module MIO_BUS(input clk,
					input rst,
					input[3:0]BTN,
					input[15:0]SW,
					input mem_w,
					input[31:0]Cpu_data2bus,				//data from CPU
					input[31:0]addr_bus,
					input[31:0]ram_data_out,
					input[15:0]led_out,
					input[31:0]counter_out,
					input counter0_out,
					input counter1_out,
					input counter2_out,
					
					output reg[31:0]Cpu_data4bus,				//write to CPU
					output reg[31:0]ram_data_in,				//from CPU write to Memory
					output reg[9:0]ram_addr,						//Memory Address signals
					output reg data_ram_we,
					output reg GPIOf0000000_we,
					output reg GPIOe0000000_we,
					output reg counter_we,
					output reg[31:0]Peripheral_in
					);
															
endmodule
