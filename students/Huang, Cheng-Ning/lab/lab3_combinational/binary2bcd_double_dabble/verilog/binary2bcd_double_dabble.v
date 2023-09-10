`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/23/2023 05:26:44 PM
// Design Name:
// Module Name: binary2bcd_double_dabble
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


module binary2bcd_double_dabble(binary_in, bcd_out, packed_bcd_out);

    input [7:0] binary_in;
    output reg [7:0] bcd_out;
    output reg [15:0] packed_bcd_out;

    reg [15:0] scratchpad;

    integer i;
        
    always @(*) begin
        scratchpad = {8'b0, binary_in};
        //double dabble
        for(i=0; i<7; i=i+1)
        begin
            scratchpad = scratchpad << 1;
            if(scratchpad[11:8] > 4'd4)
                scratchpad[11:8] = scratchpad[11:8] + 3;
        end
        scratchpad = scratchpad << 1;
        bcd_out = scratchpad[15:8];
        packed_bcd_out = {4'b0, scratchpad[15:12], 4'b0, scratchpad[11:8]};
    end
endmodule
