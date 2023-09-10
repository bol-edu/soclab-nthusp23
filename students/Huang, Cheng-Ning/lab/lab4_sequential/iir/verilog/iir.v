`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/26/2023 12:10:52 PM
// Design Name:
// Module Name: iir
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

//y = 6x + (x-1) + 2(x-2) - 4(y-1) - 3(y-2)
module iir(clk,
           rst_n,
           x,
           y);
    
    input clk;
    input rst_n;
    input signed [31:0] x;
    output reg signed [31:0] y;
    
    reg signed [31:0] y1;
    reg signed [31:0] y2;
    reg signed [31:0] x1;
    reg signed [31:0] x2;

    //combinational logic
    always@(*)
    begin
        y = 6*x + (x1) + 2*(x2) - 4*(y1) - 3*(y2);
    end

    //sequential logic
    always@(posedge clk or negedge rst_n)
    begin
        if(~rst_n)
        begin
            y1 <= 0;
            y2 <= 0;
            x1 <= 0;
            x2 <= 0;
        end
        else
        begin
            y1 <= y;
            y2 <= y1;
            x1 <= x;
            x2 <= x1;
        end
    end

endmodule
