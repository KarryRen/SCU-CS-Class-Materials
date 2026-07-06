module LED_ctrl( 
    input [15:0] sw, 
    input clk200P, 
	 input clk200N,
    input reset, 
    output reg led_do, 
    output led_pen, 
    output led_clk, 
    output led_clr 
    ); 
  wire Clk_100M; 
  reg [15:0] sw_d1; 
  parameter piso_shift = 16; 
  reg [piso_shift-2:0] sw_shift; 
  reg [16:0] counter = 17'h0; 
  wire [15:0] shift_load; 

  SWORD_LED_CLK ClkGen100M 
  (// Clock in ports 
  .CLK_IN1_P(clk200P), // IN 
  .CLK_IN1_N(clk200N),
  // Clock out ports 
  .CLK_OUT1(Clk_100M), // OUT 
  // Status and control signals 
  .RESET(RESET),// IN 
  .LOCKED(LOCKED)); 

  always@(posedge Clk_100M) 
      if(!reset) sw_d1 <= 16'h0; 
      else sw_d1 <= sw;
  assign shift_load = sw^sw_d1; 
  always @(posedge Clk_100M) 
       if (shift_load) begin 
           sw_shift <= sw[piso_shift-2:0]; 
           led_do <= ~sw[15]; 
           counter <= 17'h1ffff; 
       end 
       else begin 
           sw_shift <= {sw_shift[piso_shift-3:0], 1'b0}; 
           led_do <= ~sw_shift[14]; 
           counter <= {1'b0, counter[16:1]}; 
       end 
  assign led_clk = Clk_100M & counter[0]; 
  assign led_clr = reset; 
  assign led_pen = 1'b1; 
endmodule
