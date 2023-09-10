`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: NTHU
// Engineer: HUANG, CHENG-NING
//
// Create Date: 08/18/2023 05:57:12 AM
// Design Name:
// Module Name: single_cycle_regular_pulses
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


module single_cycle_regular_pulses(clk, rst_n, periodic_pulses);
    input clk;
    input rst_n;
    output reg periodic_pulses;
    
    reg[4:0] cnt;
    reg [4:0] cnt_next;
    
    //combinational logic
    always@(*)
    begin
        periodic_pulses = ~|cnt;
        if (periodic_pulses)
        begin
            cnt_next = 19;
        end
        else
        begin
            cnt_next = cnt-1;
        end
    end
    
    //sequential logic
    always@(posedge clk or negedge rst_n)
    begin
        if (!rst_n)
        begin
            cnt <= 19;
        end
        else
            cnt <= cnt_next;
    end
endmodule
