`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/23/2023 08:19:55 PM
// Design Name:
// Module Name: parity_generator_tb
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


module parity_generator_tb();
    
    reg [15:0] binary_in;
    wire parity;

    parity_generator parity_generator_0(
        .binary_in(binary_in),
        .parity(parity)
    );

    integer i;
    reg expected_parity;

    initial
    begin
        binary_in = 0;

        for (i = 0; i < 65536; i = i + 1) begin
            binary_in = i;
            #1

            expected_parity = 1'b0;
            for (integer j = 0; j < 16; j = j + 1) begin
                expected_parity = expected_parity ^ binary_in[j];
            end

            if (parity != expected_parity)
            begin
                $display("===Test Failed===");
                $display("Binary: %b, Expected_parity: %b,Parity: %b", binary_in, expected_parity, parity);
                $finish;
            end
        end
        $display("===Test Passed===");
    end
endmodule
