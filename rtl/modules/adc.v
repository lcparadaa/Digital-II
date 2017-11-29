module adc 
#(
	parameter   clk_freq         = 100000000,
	parameter   uart_baud_rate   = 115200
)

(
	input rst;
	input clk; 
	output [7:0] do_data; // Información traída por el adc
)






endmodule