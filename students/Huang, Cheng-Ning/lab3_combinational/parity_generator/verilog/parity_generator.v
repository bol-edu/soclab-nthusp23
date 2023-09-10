`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/23/2023 08:16:23 PM
// Design Name:
// Module Name: parity_generator
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


module parity_generator(binary_in, parity);

    input [15:0] binary_in;
    output reg parity;

    integer i;
    
    always @(*)
    begin
        parity = 0;
        for(i=0; i<16; i=i+1)
            parity = parity ^ binary_in[i];
    end
endmodule
