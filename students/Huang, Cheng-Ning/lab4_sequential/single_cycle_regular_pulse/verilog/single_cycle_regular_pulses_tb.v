`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: NTHU
// Engineer: HUANG, CHENG-NING
//
// Create Date: 08/18/2023 06:08:48 AM
// Design Name:
// Module Name: single_cycle_regular_pulses_tb
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


module single_cycle_regular_pulses_tb();
    
    reg clk;
    reg rst_n;
    wire periodic_pulses;
    
    single_cycle_regular_pulses single_cycle_regular_pulses_0(.clk(clk), .rst_n(rst_n), .periodic_pulses(periodic_pulses));
    
    always #10 clk = ~clk;
    
    initial
    begin
        clk       = 1;
        rst_n     = 1;
        #100 rst_n = 0;
        #10 rst_n = 1;
        #1000 $finish;
    end
    
endmodule
