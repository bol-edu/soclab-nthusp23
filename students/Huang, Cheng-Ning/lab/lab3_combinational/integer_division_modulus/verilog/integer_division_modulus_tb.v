`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/23/2023 10:29:54 PM
// Design Name:
// Module Name: integer_division_modulus_tb
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


module integer_division_modulus_tb();

    reg [31:0] a;
    wire [3:0] r;

    integer_division_modulus integer_division_modulus_0(
        .a(a),
        .r(r)
    );

    integer i;
    reg [3:0] expected_r;

    initial
    begin
        a = 0;

        for (i = 0; i < 65536; i = i + 1) begin
            a = i;
            #1

            expected_r = i % 10;

            if (r != expected_r)
            begin
                $display("===Test Failed===");
                $display("a: %d, Expected_r: %d,r: %d", a, expected_r, r);
                $finish;
            end
        end
        $display("===Test Passed===");
    end
endmodule
