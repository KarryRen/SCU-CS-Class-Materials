////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: top_synthesis.v
// /___/   /\     Timestamp: Thu Nov 14 09:26:11 2024
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim top.ngc top_synthesis.v 
// Device	: xc7k325t-1-ffg676
// Input file	: top.ngc
// Output file	: C:\Documents and Settings\adder_4bit\netgen\synthesis\top_synthesis.v
// # of Modules	: 1
// Design Name	: top
// Xilinx        : D:\Xilinx\14.7\ISE_DS\ISE\
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module top (
  clk200P, clk200N, RSTN, LEDCLK, LEDDT, LEDCLR, a, b
);
  input clk200P;
  input clk200N;
  input RSTN;
  output LEDCLK;
  output LEDDT;
  output LEDCLR;
  input [3 : 0] a;
  input [3 : 0] b;
  wire a_3_IBUF_0;
  wire a_2_IBUF_1;
  wire a_1_IBUF_2;
  wire a_0_IBUF_3;
  wire b_3_IBUF_4;
  wire b_2_IBUF_5;
  wire b_1_IBUF_6;
  wire b_0_IBUF_7;
  wire co;
  wire \U2/led_do_15 ;
  wire LEDCLK_OBUF_16;
  wire RSTN_IBUF_17;
  wire N0;
  wire N1;
  wire co_bdd2;
  wire \U2/ClkGen100M/clkin1 ;
  wire \U2/ClkGen100M/clkfbout ;
  wire \U2/ClkGen100M/clkout0 ;
  wire \U2/ClkGen100M/clkfbout_buf ;
  wire \U2/reset_inv ;
  wire \U2/sw_shift[14]_sw[15]_MUX_32_o ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<0> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<1> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<2> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<3> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<4> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<5> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<6> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<7> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<8> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<9> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<10> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<11> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<12> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<13> ;
  wire \U2/sw_shift[13]_sw[14]_mux_6_OUT<14> ;
  wire \U2/Clk_100M ;
  wire N01;
  wire N2;
  wire N5;
  wire \U2/counter_16_rstpot ;
  wire \U2/counter_15_rstpot_96 ;
  wire \U2/counter_14_rstpot_97 ;
  wire \U2/counter_13_rstpot_98 ;
  wire \U2/counter_12_rstpot_99 ;
  wire \U2/counter_11_rstpot_100 ;
  wire \U2/counter_10_rstpot_101 ;
  wire \U2/counter_9_rstpot_102 ;
  wire \U2/counter_8_rstpot_103 ;
  wire \U2/counter_7_rstpot_104 ;
  wire \U2/counter_6_rstpot_105 ;
  wire \U2/counter_5_rstpot_106 ;
  wire \U2/counter_4_rstpot_107 ;
  wire \U2/counter_3_rstpot_108 ;
  wire \U2/counter_2_rstpot_109 ;
  wire \U2/counter_1_rstpot_110 ;
  wire \U2/counter_0_rstpot_111 ;
  wire N7;
  wire N8;
  wire \U2/sw_d1_3_1_114 ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT3_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT3B_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKFBSTOPPED_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKFBOUTB_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT1_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT5_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DRDY_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT4_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT1B_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKINSTOPPED_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT0B_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT2_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT2B_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_PSDONE_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT6_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_LOCKED_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<15>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<14>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<13>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<12>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<11>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<10>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<9>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<8>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<7>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<6>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<5>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<4>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<3>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<2>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<1>_UNCONNECTED ;
  wire \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<0>_UNCONNECTED ;
  wire [3 : 0] s;
  wire [16 : 0] \U2/counter ;
  wire [14 : 0] \U2/sw_shift ;
  wire [4 : 0] \U2/sw_d1 ;
  VCC   XST_VCC (
    .P(N0)
  );
  GND   XST_GND (
    .G(N1)
  );
  IBUFGDS #(
    .CAPACITANCE ( "DONT_CARE" ),
    .DIFF_TERM ( "FALSE" ),
    .IBUF_DELAY_VALUE ( "0" ),
    .IBUF_LOW_PWR ( "TRUE" ),
    .IOSTANDARD ( "DEFAULT" ))
  \U2/ClkGen100M/clkin1_buf  (
    .I(clk200P),
    .IB(clk200N),
    .O(\U2/ClkGen100M/clkin1 )
  );
  MMCME2_ADV #(
    .BANDWIDTH ( "OPTIMIZED" ),
    .CLKFBOUT_USE_FINE_PS ( "FALSE" ),
    .CLKOUT0_USE_FINE_PS ( "FALSE" ),
    .CLKOUT1_USE_FINE_PS ( "FALSE" ),
    .CLKOUT2_USE_FINE_PS ( "FALSE" ),
    .CLKOUT3_USE_FINE_PS ( "FALSE" ),
    .CLKOUT4_CASCADE ( "FALSE" ),
    .CLKOUT4_USE_FINE_PS ( "FALSE" ),
    .CLKOUT5_USE_FINE_PS ( "FALSE" ),
    .CLKOUT6_USE_FINE_PS ( "FALSE" ),
    .COMPENSATION ( "ZHOLD" ),
    .SS_EN ( "FALSE" ),
    .SS_MODE ( "CENTER_HIGH" ),
    .STARTUP_WAIT ( "FALSE" ),
    .CLKOUT1_DIVIDE ( 1 ),
    .CLKOUT2_DIVIDE ( 1 ),
    .CLKOUT3_DIVIDE ( 1 ),
    .CLKOUT4_DIVIDE ( 1 ),
    .CLKOUT5_DIVIDE ( 1 ),
    .CLKOUT6_DIVIDE ( 1 ),
    .DIVCLK_DIVIDE ( 1 ),
    .SS_MOD_PERIOD ( 10000 ),
    .CLKFBOUT_MULT_F ( 10.000000 ),
    .CLKFBOUT_PHASE ( 0.000000 ),
    .CLKIN1_PERIOD ( 10.000000 ),
    .CLKIN2_PERIOD ( 0.000000 ),
    .CLKOUT0_DIVIDE_F ( 10.000000 ),
    .CLKOUT0_DUTY_CYCLE ( 0.500000 ),
    .CLKOUT0_PHASE ( 0.000000 ),
    .CLKOUT1_DUTY_CYCLE ( 0.500000 ),
    .CLKOUT1_PHASE ( 0.000000 ),
    .CLKOUT2_DUTY_CYCLE ( 0.500000 ),
    .CLKOUT2_PHASE ( 0.000000 ),
    .CLKOUT3_DUTY_CYCLE ( 0.500000 ),
    .CLKOUT3_PHASE ( 0.000000 ),
    .CLKOUT4_DUTY_CYCLE ( 0.500000 ),
    .CLKOUT4_PHASE ( 0.000000 ),
    .CLKOUT5_DUTY_CYCLE ( 0.500000 ),
    .CLKOUT5_PHASE ( 0.000000 ),
    .CLKOUT6_DUTY_CYCLE ( 0.500000 ),
    .CLKOUT6_PHASE ( 0.000000 ),
    .REF_JITTER1 ( 0.010000 ),
    .REF_JITTER2 ( 0.010000 ))
  \U2/ClkGen100M/mmcm_adv_inst  (
    .CLKOUT3(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT3_UNCONNECTED ),
    .CLKFBIN(\U2/ClkGen100M/clkfbout_buf ),
    .PSCLK(N1),
    .CLKOUT3B(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT3B_UNCONNECTED ),
    .PWRDWN(N1),
    .DCLK(N1),
    .CLKFBOUT(\U2/ClkGen100M/clkfbout ),
    .CLKFBSTOPPED(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKFBSTOPPED_UNCONNECTED ),
    .CLKFBOUTB(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKFBOUTB_UNCONNECTED ),
    .CLKOUT1(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT1_UNCONNECTED ),
    .DEN(N1),
    .CLKOUT5(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT5_UNCONNECTED ),
    .CLKINSEL(N0),
    .CLKIN2(N1),
    .DRDY(\NLW_U2/ClkGen100M/mmcm_adv_inst_DRDY_UNCONNECTED ),
    .RST(N1),
    .PSINCDEC(N1),
    .DWE(N1),
    .PSEN(N1),
    .CLKOUT0(\U2/ClkGen100M/clkout0 ),
    .CLKOUT4(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT4_UNCONNECTED ),
    .CLKOUT1B(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT1B_UNCONNECTED ),
    .CLKINSTOPPED(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKINSTOPPED_UNCONNECTED ),
    .CLKOUT0B(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT0B_UNCONNECTED ),
    .CLKIN1(\U2/ClkGen100M/clkin1 ),
    .CLKOUT2(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT2_UNCONNECTED ),
    .CLKOUT2B(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT2B_UNCONNECTED ),
    .PSDONE(\NLW_U2/ClkGen100M/mmcm_adv_inst_PSDONE_UNCONNECTED ),
    .CLKOUT6(\NLW_U2/ClkGen100M/mmcm_adv_inst_CLKOUT6_UNCONNECTED ),
    .LOCKED(\NLW_U2/ClkGen100M/mmcm_adv_inst_LOCKED_UNCONNECTED ),
    .DI({N1, N1, N1, N1, N1, N1, N1, N1, N1, N1, N1, N1, N1, N1, N1, N1}),
    .DO({\NLW_U2/ClkGen100M/mmcm_adv_inst_DO<15>_UNCONNECTED , \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<14>_UNCONNECTED , 
\NLW_U2/ClkGen100M/mmcm_adv_inst_DO<13>_UNCONNECTED , \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<12>_UNCONNECTED , 
\NLW_U2/ClkGen100M/mmcm_adv_inst_DO<11>_UNCONNECTED , \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<10>_UNCONNECTED , 
\NLW_U2/ClkGen100M/mmcm_adv_inst_DO<9>_UNCONNECTED , \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<8>_UNCONNECTED , 
\NLW_U2/ClkGen100M/mmcm_adv_inst_DO<7>_UNCONNECTED , \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<6>_UNCONNECTED , 
\NLW_U2/ClkGen100M/mmcm_adv_inst_DO<5>_UNCONNECTED , \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<4>_UNCONNECTED , 
\NLW_U2/ClkGen100M/mmcm_adv_inst_DO<3>_UNCONNECTED , \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<2>_UNCONNECTED , 
\NLW_U2/ClkGen100M/mmcm_adv_inst_DO<1>_UNCONNECTED , \NLW_U2/ClkGen100M/mmcm_adv_inst_DO<0>_UNCONNECTED }),
    .DADDR({N1, N1, N1, N1, N1, N1, N1})
  );
  BUFG   \U2/ClkGen100M/clkf_buf  (
    .O(\U2/ClkGen100M/clkfbout_buf ),
    .I(\U2/ClkGen100M/clkfbout )
  );
  BUFG   \U2/ClkGen100M/clkout1_buf  (
    .O(\U2/Clk_100M ),
    .I(\U2/ClkGen100M/clkout0 )
  );
  FD   \U2/led_do  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[14]_sw[15]_MUX_32_o ),
    .Q(\U2/led_do_15 )
  );
  FD   \U2/sw_shift_14  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<14> ),
    .Q(\U2/sw_shift [14])
  );
  FD   \U2/sw_shift_13  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<13> ),
    .Q(\U2/sw_shift [13])
  );
  FD   \U2/sw_shift_12  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<12> ),
    .Q(\U2/sw_shift [12])
  );
  FD   \U2/sw_shift_11  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<11> ),
    .Q(\U2/sw_shift [11])
  );
  FD   \U2/sw_shift_10  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<10> ),
    .Q(\U2/sw_shift [10])
  );
  FD   \U2/sw_shift_9  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<9> ),
    .Q(\U2/sw_shift [9])
  );
  FD   \U2/sw_shift_8  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<8> ),
    .Q(\U2/sw_shift [8])
  );
  FD   \U2/sw_shift_7  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<7> ),
    .Q(\U2/sw_shift [7])
  );
  FD   \U2/sw_shift_6  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<6> ),
    .Q(\U2/sw_shift [6])
  );
  FD   \U2/sw_shift_5  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<5> ),
    .Q(\U2/sw_shift [5])
  );
  FD   \U2/sw_shift_4  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<4> ),
    .Q(\U2/sw_shift [4])
  );
  FD   \U2/sw_shift_3  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<3> ),
    .Q(\U2/sw_shift [3])
  );
  FD   \U2/sw_shift_2  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<2> ),
    .Q(\U2/sw_shift [2])
  );
  FD   \U2/sw_shift_1  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<1> ),
    .Q(\U2/sw_shift [1])
  );
  FD   \U2/sw_shift_0  (
    .C(\U2/Clk_100M ),
    .D(\U2/sw_shift[13]_sw[14]_mux_6_OUT<0> ),
    .Q(\U2/sw_shift [0])
  );
  FDR   \U2/sw_d1_4  (
    .C(\U2/Clk_100M ),
    .D(co),
    .R(\U2/reset_inv ),
    .Q(\U2/sw_d1 [4])
  );
  FDR   \U2/sw_d1_3  (
    .C(\U2/Clk_100M ),
    .D(s[3]),
    .R(\U2/reset_inv ),
    .Q(\U2/sw_d1 [3])
  );
  FDR   \U2/sw_d1_2  (
    .C(\U2/Clk_100M ),
    .D(s[2]),
    .R(\U2/reset_inv ),
    .Q(\U2/sw_d1 [2])
  );
  FDR   \U2/sw_d1_1  (
    .C(\U2/Clk_100M ),
    .D(s[1]),
    .R(\U2/reset_inv ),
    .Q(\U2/sw_d1 [1])
  );
  FDR   \U2/sw_d1_0  (
    .C(\U2/Clk_100M ),
    .D(s[0]),
    .R(\U2/reset_inv ),
    .Q(\U2/sw_d1 [0])
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  \U1/a1/Mxor_s_xo<0>1  (
    .I0(a_0_IBUF_3),
    .I1(b_0_IBUF_7),
    .O(s[0])
  );
  LUT5 #(
    .INIT ( 32'h99969666 ))
  \s<3>1  (
    .I0(a_3_IBUF_0),
    .I1(b_3_IBUF_4),
    .I2(b_2_IBUF_5),
    .I3(a_2_IBUF_1),
    .I4(co_bdd2),
    .O(s[3])
  );
  LUT5 #(
    .INIT ( 32'hFEEAA880 ))
  co1 (
    .I0(b_3_IBUF_4),
    .I1(b_2_IBUF_5),
    .I2(a_2_IBUF_1),
    .I3(co_bdd2),
    .I4(a_3_IBUF_0),
    .O(co)
  );
  LUT4 #(
    .INIT ( 16'hEA80 ))
  co21 (
    .I0(a_1_IBUF_2),
    .I1(a_0_IBUF_3),
    .I2(b_0_IBUF_7),
    .I3(b_1_IBUF_6),
    .O(co_bdd2)
  );
  LUT4 #(
    .INIT ( 16'h8778 ))
  \s<1>1  (
    .I0(a_0_IBUF_3),
    .I1(b_0_IBUF_7),
    .I2(a_1_IBUF_2),
    .I3(b_1_IBUF_6),
    .O(s[1])
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  \U2/led_clk1  (
    .I0(\U2/Clk_100M ),
    .I1(\U2/counter [0]),
    .O(LEDCLK_OBUF_16)
  );
  LUT6 #(
    .INIT ( 64'h7FBFDFEFF7FBFDFE ))
  \U2/out_SW0  (
    .I0(s[2]),
    .I1(s[1]),
    .I2(s[0]),
    .I3(\U2/sw_d1 [2]),
    .I4(\U2/sw_d1 [1]),
    .I5(\U2/sw_d1 [0]),
    .O(N01)
  );
  LUT5 #(
    .INIT ( 32'hFFFF6FF6 ))
  \U2/out  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(N01),
    .O(\U2/counter_16_rstpot )
  );
  IBUF   a_3_IBUF (
    .I(a[3]),
    .O(a_3_IBUF_0)
  );
  IBUF   a_2_IBUF (
    .I(a[2]),
    .O(a_2_IBUF_1)
  );
  IBUF   a_1_IBUF (
    .I(a[1]),
    .O(a_1_IBUF_2)
  );
  IBUF   a_0_IBUF (
    .I(a[0]),
    .O(a_0_IBUF_3)
  );
  IBUF   b_3_IBUF (
    .I(b[3]),
    .O(b_3_IBUF_4)
  );
  IBUF   b_2_IBUF (
    .I(b[2]),
    .O(b_2_IBUF_5)
  );
  IBUF   b_1_IBUF (
    .I(b[1]),
    .O(b_1_IBUF_6)
  );
  IBUF   b_0_IBUF (
    .I(b[0]),
    .O(b_0_IBUF_7)
  );
  IBUF   RSTN_IBUF (
    .I(RSTN),
    .O(RSTN_IBUF_17)
  );
  OBUF   LEDCLK_OBUF (
    .I(LEDCLK_OBUF_16),
    .O(LEDCLK)
  );
  OBUF   LEDDT_OBUF (
    .I(\U2/led_do_15 ),
    .O(LEDDT)
  );
  OBUF   LEDCLR_OBUF (
    .I(RSTN_IBUF_17),
    .O(LEDCLR)
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFF7FBFDFEF ))
  \U2/Mmux_sw_shift[14]_sw[15]_MUX_32_o11  (
    .I0(s[3]),
    .I1(co),
    .I2(\U2/sw_shift [14]),
    .I3(\U2/sw_d1 [3]),
    .I4(\U2/sw_d1 [4]),
    .I5(N01),
    .O(\U2/sw_shift[14]_sw[15]_MUX_32_o )
  );
  LUT6 #(
    .INIT ( 64'hAAAAAAAA28AAAA28 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT16  (
    .I0(s[0]),
    .I1(\U2/sw_d1 [3]),
    .I2(s[3]),
    .I3(\U2/sw_d1 [4]),
    .I4(co),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<0> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT21  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [9]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<10> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT31  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [10]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<11> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT41  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [11]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<12> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT51  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [12]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<13> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT61  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [13]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<14> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT111  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [4]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<5> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT121  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [5]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<6> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT131  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [6]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<7> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT141  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [7]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<8> )
  );
  LUT6 #(
    .INIT ( 64'h0000000080402010 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT151  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_shift [8]),
    .I3(\U2/sw_d1 [4]),
    .I4(\U2/sw_d1 [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<9> )
  );
  LUT6 #(
    .INIT ( 64'hAAAAAAAABAAB2AA2 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT91  (
    .I0(s[3]),
    .I1(\U2/sw_d1 [3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/sw_shift [2]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<3> )
  );
  LUT6 #(
    .INIT ( 64'hAAAAAAAABAAB2AA2 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT101  (
    .I0(co),
    .I1(\U2/sw_d1 [4]),
    .I2(s[3]),
    .I3(\U2/sw_d1 [3]),
    .I4(\U2/sw_shift [3]),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<4> )
  );
  LUT5 #(
    .INIT ( 32'hCCCCED48 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT71  (
    .I0(co),
    .I1(s[1]),
    .I2(\U2/sw_d1 [4]),
    .I3(N2),
    .I4(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<1> )
  );
  LUT4 #(
    .INIT ( 16'h8421 ))
  \U2/out_SW3  (
    .I0(co),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(\U2/sw_d1 [3]),
    .O(N5)
  );
  LUT6 #(
    .INIT ( 64'h96969696FF009696 ))
  \U2/Mmux_sw_shift[13]_sw[14]_mux_6_OUT81  (
    .I0(a_2_IBUF_1),
    .I1(b_2_IBUF_5),
    .I2(co_bdd2),
    .I3(\U2/sw_shift [1]),
    .I4(N5),
    .I5(N01),
    .O(\U2/sw_shift[13]_sw[14]_mux_6_OUT<2> )
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_16  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_16_rstpot ),
    .Q(\U2/counter [16])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_15  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_15_rstpot_96 ),
    .Q(\U2/counter [15])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_14  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_14_rstpot_97 ),
    .Q(\U2/counter [14])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_13  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_13_rstpot_98 ),
    .Q(\U2/counter [13])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_12  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_12_rstpot_99 ),
    .Q(\U2/counter [12])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_11  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_11_rstpot_100 ),
    .Q(\U2/counter [11])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_10  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_10_rstpot_101 ),
    .Q(\U2/counter [10])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_9  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_9_rstpot_102 ),
    .Q(\U2/counter [9])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_8  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_8_rstpot_103 ),
    .Q(\U2/counter [8])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_7  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_7_rstpot_104 ),
    .Q(\U2/counter [7])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_6  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_6_rstpot_105 ),
    .Q(\U2/counter [6])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_5  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_5_rstpot_106 ),
    .Q(\U2/counter [5])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_4  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_4_rstpot_107 ),
    .Q(\U2/counter [4])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_3  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_3_rstpot_108 ),
    .Q(\U2/counter [3])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_2  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_2_rstpot_109 ),
    .Q(\U2/counter [2])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_1  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_1_rstpot_110 ),
    .Q(\U2/counter [1])
  );
  FD #(
    .INIT ( 1'b0 ))
  \U2/counter_0  (
    .C(\U2/Clk_100M ),
    .D(\U2/counter_0_rstpot_111 ),
    .Q(\U2/counter [0])
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_15_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [16]),
    .I5(N01),
    .O(\U2/counter_15_rstpot_96 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_14_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [15]),
    .I5(N01),
    .O(\U2/counter_14_rstpot_97 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_13_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [14]),
    .I5(N01),
    .O(\U2/counter_13_rstpot_98 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_12_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [13]),
    .I5(N01),
    .O(\U2/counter_12_rstpot_99 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_11_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [12]),
    .I5(N01),
    .O(\U2/counter_11_rstpot_100 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_10_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [11]),
    .I5(N01),
    .O(\U2/counter_10_rstpot_101 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_9_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [10]),
    .I5(N01),
    .O(\U2/counter_9_rstpot_102 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_8_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [9]),
    .I5(N01),
    .O(\U2/counter_8_rstpot_103 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_7_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [8]),
    .I5(N01),
    .O(\U2/counter_7_rstpot_104 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_6_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [7]),
    .I5(N01),
    .O(\U2/counter_6_rstpot_105 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_5_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [6]),
    .I5(N01),
    .O(\U2/counter_5_rstpot_106 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_4_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [5]),
    .I5(N01),
    .O(\U2/counter_4_rstpot_107 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_3_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [4]),
    .I5(N01),
    .O(\U2/counter_3_rstpot_108 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_2_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [3]),
    .I5(N01),
    .O(\U2/counter_2_rstpot_109 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_1_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [2]),
    .I5(N01),
    .O(\U2/counter_1_rstpot_110 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFF6FF6 ))
  \U2/counter_0_rstpot  (
    .I0(\U2/sw_d1 [3]),
    .I1(s[3]),
    .I2(\U2/sw_d1 [4]),
    .I3(co),
    .I4(\U2/counter [1]),
    .I5(N01),
    .O(\U2/counter_0_rstpot_111 )
  );
  MUXF7   \U2/out_SW1  (
    .I0(N7),
    .I1(N8),
    .S(\U2/sw_d1_3_1_114 ),
    .O(N2)
  );
  LUT6 #(
    .INIT ( 64'h9666FFFF96660000 ))
  \U2/out_SW1_F  (
    .I0(b_1_IBUF_6),
    .I1(a_1_IBUF_2),
    .I2(b_0_IBUF_7),
    .I3(a_0_IBUF_3),
    .I4(s[3]),
    .I5(\U2/sw_shift [0]),
    .O(N7)
  );
  LUT6 #(
    .INIT ( 64'hFFFF936C0000936C ))
  \U2/out_SW1_G  (
    .I0(a_0_IBUF_3),
    .I1(a_1_IBUF_2),
    .I2(b_0_IBUF_7),
    .I3(b_1_IBUF_6),
    .I4(s[3]),
    .I5(\U2/sw_shift [0]),
    .O(N8)
  );
  LUT6 #(
    .INIT ( 64'h9996969696666666 ))
  \s<2>1  (
    .I0(b_2_IBUF_5),
    .I1(a_2_IBUF_1),
    .I2(a_1_IBUF_2),
    .I3(a_0_IBUF_3),
    .I4(b_0_IBUF_7),
    .I5(b_1_IBUF_6),
    .O(s[2])
  );
  FDR   \U2/sw_d1_3_1  (
    .C(\U2/Clk_100M ),
    .D(s[3]),
    .R(\U2/reset_inv ),
    .Q(\U2/sw_d1_3_1_114 )
  );
  INV   \U2/reset_inv1_INV_0  (
    .I(RSTN_IBUF_17),
    .O(\U2/reset_inv )
  );
endmodule


`ifndef GLBL
`define GLBL

`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;

    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule

`endif

