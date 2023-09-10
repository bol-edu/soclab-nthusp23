`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/21/2023 12:03:02 PM
// Design Name:
// Module Name: bcd_counter_multicycle_tb
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


module bcd_counter_multicycle_tb();

    reg clk;
    reg pulse;
    reg rst_n;
    wire [7:0] seven_segment_data;
    wire [3:0] seven_segment_enable;

    bcd_counter_multicycle bcd_counter_multicycle_0(.clk(clk), .rst_n(rst_n), .pulse(pulse), .seven_segment_data(seven_segment_data), .seven_segment_enable(seven_segment_enable));

    always #10 clk = ~clk;
    always #20 pulse = ~pulse;

    initial
    begin
        clk       = 1;
        pulse     = 0;
        rst_n     = 1;
        #100 rst_n = 0;
        #10 rst_n = 1;
        #1000 $finish;
    end
endmodule
