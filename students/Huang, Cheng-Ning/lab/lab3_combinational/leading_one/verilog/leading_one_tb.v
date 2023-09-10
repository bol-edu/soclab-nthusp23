`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/24/2023 12:17:14 PM
// Design Name:
// Module Name: leading_one_tb
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


module leading_one_tb();

    reg [8:0] binary_in;
    wire [4:0] leading_one;

    leading_one leading_one_0(
        .binary_in(binary_in),
        .leading_one(leading_one)
    );

    integer i;
    reg [4:0] expected_leading_one;

    initial
    begin
        binary_in = 0;

        for (i = 0; i < 512; i = i + 1) begin
            binary_in = i;
            #1

            expected_leading_one = -5'd1;
            for (integer j = 0; j <= 8; j = j + 1) begin
                if (binary_in[j] == 1)
                    expected_leading_one = j;
            end

            if (leading_one != expected_leading_one)
            begin
                $display("===Test Failed===");
                $display("Binary: %b, Expected_leading_one: %d,Leading_one: %d", binary_in, expected_leading_one, leading_one);
                $finish;
            end
        end
        $display("===Test Passed===");
    end
endmodule
