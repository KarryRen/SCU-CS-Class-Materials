// file: SWORD_LED_CLK_exdes.v
// 
// (c) Copyright 2008 - 2011 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 

//----------------------------------------------------------------------------
// Clocking wizard example design
//----------------------------------------------------------------------------
// This example design instantiates the created clocking network, where each
//   output clock drives a counter. The high bit of each counter is ported.
//----------------------------------------------------------------------------

`timescale 1ps/1ps

module SWORD_LED_CLK_exdes 
 #( 
  parameter TCQ = 100
  )
 (// Clock in ports
  input         CLK_IN1_P,
  input         CLK_IN1_N,
  // Reset that only drives logic in example design
  input         COUNTER_RESET,
  output [1:1]  CLK_OUT,
  // High bits of counters driven by clocks
  output        COUNT,
  // Status and control signals
  input         RESET,
  output        LOCKED
 );

  // Parameters for the counters
  //-------------------------------
  // Counter width
  localparam    C_W       = 16;
  // When the clock goes out of lock, reset the counters
  wire          reset_int = !LOCKED || RESET || COUNTER_RESET;

   reg rst_sync;
   reg rst_sync_int;
   reg rst_sync_int1;
   reg rst_sync_int2;



  // Declare the clocks and counter
  wire           clk_int;
  wire           clk;
  reg  [C_W-1:0] counter;

  // Instantiation of the clocking network
  //--------------------------------------
  SWORD_LED_CLK clknetwork
   (// Clock in ports
    .CLK_IN1_P          (CLK_IN1_P),
    .CLK_IN1_N          (CLK_IN1_N),
    // Clock out ports
    .CLK_OUT1           (clk_int),
    // Status and control signals
    .RESET              (RESET),
    .LOCKED             (LOCKED));


  ODDR clk_out_oddr
   (.Q  (CLK_OUT[1]),
    .C  (clk),
    .CE (1'b1),
    .D1 (1'b1),
    .D2 (1'b0),
    .R  (1'b0),
    .S  (1'b0));

  // Connect the output clocks to the design
  //-----------------------------------------
  assign clk = clk_int;


  // Reset synchronizer
  //-----------------------------------
    always @(posedge reset_int or posedge clk) begin
       if (reset_int) begin
            rst_sync <= 1'b1;
            rst_sync_int <= 1'b1;
            rst_sync_int1 <= 1'b1;
            rst_sync_int2 <= 1'b1;
       end
       else begin
            rst_sync <= 1'b0;
            rst_sync_int <= rst_sync;     
            rst_sync_int1 <= rst_sync_int; 
            rst_sync_int2 <= rst_sync_int1;
       end
    end


  // Output clock sampling
  //-----------------------------------
  always @(posedge clk or posedge rst_sync_int2) begin
    if (rst_sync_int2) begin
      counter <= #TCQ { C_W { 1'b 0 } };
    end else begin
      counter <= #TCQ counter + 1'b 1;
    end
  end

  // alias the high bit to the output
  assign COUNT = counter[C_W-1];



endmodule
