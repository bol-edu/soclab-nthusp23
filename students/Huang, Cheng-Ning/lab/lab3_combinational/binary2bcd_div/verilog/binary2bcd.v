`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:NTHU
// Engineer:HUANG, CHENG-NING

//
// Create Date: 08/17/2023 10:06:41 AM
// Design Name:binary2bcd_div
// Module Name: binary2bcd
// Project Name:binary2bcd_div
// Target Devices:Basys3
// Tool Versions:vivado2022.1
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////


module binary2bcd(binary_in,
                  bcd);

    input [13:0] binary_in;
    output reg [15:0] bcd;

    reg[13:0] binary;
    reg[13:0] binary_next;
    reg[3:0] bcd_0;
    reg[3:0] bcd_1;
    reg[3:0] bcd_2;
    reg[3:0] bcd_3;

    always @(*)
    begin
        binary = binary_in;

        binary_next = binary/10;
        bcd_0 = binary - binary_next*10;
        binary = binary_next;

        binary_next = binary/10;
        bcd_1 = binary - binary_next*10;
        binary = binary_next;

        binary_next = binary/10;
        bcd_2 = binary - binary_next*10;
        binary = binary_next;

        binary_next = binary/10;
        bcd_3 = binary - binary_next*10;

        bcd = {bcd_3,bcd_2,bcd_1,bcd_0};
    end
endmodule
