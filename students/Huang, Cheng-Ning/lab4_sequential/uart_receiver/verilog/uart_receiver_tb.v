`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/28/2023 07:04:36 PM
// Design Name:
// Module Name: uart_receiver_tb
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////


module uart_receiver_tb();
    
    reg clk;
    reg rst_n;
    reg baud_rate_signal;
    reg [7:0] data_in;
    reg rx;
    
    wire [7:0] data_out;
    wire valid;
    
    integer i;
    
    uart_receiver uart_receiver_0(.clk(clk),
    .rst_n(rst_n),
    .baud_rate_signal(baud_rate_signal),
    .rx(rx),
    .data(data_out),
    .valid(valid)
    );
    
    //clock
    always #5 clk = ~clk;
    //baud_rate_signal
    always #10 baud_rate_signal = ~baud_rate_signal;
    
    initial
    begin
        clk              = 1;
        rst_n            = 1;
        baud_rate_signal = 1;
        data_in          = 8'b01000001;
        rx               = 1;
        
        #95 rst_n = 0;
        #5 rst_n  = 1;
        
        //start
        @ (posedge baud_rate_signal) rx = 0;
        for (i = 0; i < 8; i = i + 1)
        begin
            @ (posedge baud_rate_signal) rx = data_in[i];
            $display("rx                    = %b", rx);
        end
        @ (posedge baud_rate_signal) rx = 1;
    end
endmodule
