`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/24/2023 12:11:24 PM
// Design Name: 
// Module Name: leading_one
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


module leading_one(binary_in, leading_one);

    input [8:0] binary_in;
    output reg [4:0] leading_one;

    integer i;

    always @(*)
    begin
        leading_one = -5'b1;
        for (i = 0; i <= 8; i = i + 1)
        begin
            if (binary_in[i] == 1)
                leading_one = i;
        end
    end
endmodule
