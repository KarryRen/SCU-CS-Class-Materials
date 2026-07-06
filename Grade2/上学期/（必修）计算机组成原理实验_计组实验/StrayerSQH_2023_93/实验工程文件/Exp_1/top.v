module top( 
        input [3:0] a, 
        input [3:0] b, 
        input clk200P, 
		 input clk200N,
        input RSTN, 
        output LEDCLK, 
        output LEDDT, 
        output LEDCLR
        ); 
		  
       wire [3:0] s; 
       wire co; 
       wire [4:0] sum; 
       assign sum = {co, s}; 

       adder_4bits  U1 ( .a(a), .b(b), .ci(1'b0), .s(s), .co(co) ); 
       LED_ctrl  U2 ( 
         .sw({11'b0, sum}), 
			.clk200P(clk200P),
         .clk200N(clk200N), 
         .reset(RSTN), 
         .led_do(LEDDT), 
      // .led_pen(led_pen), 
         .led_clk(LEDCLK), 
         .led_clr(LEDCLR) 
         ); 
      endmodule
