`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: NTHU
// Engineer: HUANG, CHENG-NING
//
// Create Date: 08/18/2023 01:46:15 AM
// Design Name:
// Module Name: binary2bcd_tb
// Project Name:
// Target Devices: Basys3
// Tool Versions: vivado2022.1
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////


module binary2bcd_double_dabble_tb();
    
    reg status;
    reg [7:0] binary_in;
    wire [7:0] bcd_out;
    wire [15:0] packed_bcd_out;
    
    binary2bcd_double_dabble binary2bcd_double_dabble_0(
        .binary_in(binary_in),
        .bcd_out(bcd_out),
        .packed_bcd_out(packed_bcd_out)
    );
    
    initial begin
        status = 0;
        for(integer i = 0; i<100; i = i+1) begin
            binary_in = i;
            #1
            $display("binary_in = %d, bcd_out = %d%d",binary_in, bcd_out[7:4], bcd_out[3:0]);
            if (i != bcd_out[7:4]*10+bcd_out[3:0])begin
                status = 1;
                $display(" === Test Failed === ");
                $finish;
            end
        end
        $display(" === Test Passed === ");
        $finish;
    end
    
endmodule
