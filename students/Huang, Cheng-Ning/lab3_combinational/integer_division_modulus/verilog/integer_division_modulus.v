`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/23/2023 10:25:44 PM
// Design Name: 
// Module Name: integer_division_modulus
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


module integer_division_modulus(a, r);
    input [31:0] a;
    output reg [3:0] r;

    reg [31:0] tmp;

    always @(*)
    begin
        tmp = a/10;
        r = a - tmp*10;
    end

endmodule
