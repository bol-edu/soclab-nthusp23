`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/28/2023 01:40:11 PM
// Design Name:
// Module Name: uart_transmitter_tb
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


module uart_transmitter_tb();

    reg clk;
    reg rst_n;
    reg baud_rate_signal;
    reg [7:0] data_in;
    reg start;
    wire tx;

    uart_transmitter uart_transmitter_0 (
        .clk(clk),
        .rst_n(rst_n),
        .baud_rate_signal(baud_rate_signal),
        .data_in(data_in),
        .start(start),
        .tx(tx)
    );

    //clock signal
    always #5 clk <= ~clk;
    //baud rate signal
    always #10 baud_rate_signal <= ~baud_rate_signal;

    initial
    begin
        clk = 1;
        rst_n = 1;
        baud_rate_signal = 1;
        data_in = 8'b01000001;
        start = 0;
        #90 rst_n = 0;
        #10 rst_n = 1;
        #100 start = 1;
        #20 start = 0;
    end
endmodule
