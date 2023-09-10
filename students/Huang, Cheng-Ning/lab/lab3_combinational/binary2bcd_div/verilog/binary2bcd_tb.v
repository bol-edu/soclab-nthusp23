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


module binary2bcd_tb();
    
    reg status;
    reg [13:0] binary_in;
    wire [15:0] bcd;
    
    binary2bcd binary2bcd_0(
    .binary_in(binary_in),
    .bcd(bcd)
    );
    
    initial begin
        status = 0;
        for(integer i = 0; i<10000; i = i+1) begin
            binary_in = i;
            #1
            $display("binary_in = %d, bcd = %d%d%d%d",binary_in, bcd[15:12], bcd[11:8], bcd[7:4], bcd[3:0]);
            if (i != bcd[15:12]*1000+bcd[11:8]*100+bcd[7:4]*10+bcd[3:0])begin
                status = 1;
                $display(" === Test Failed === ");
                $finish;
            end
        end
        $display(" === Test Passed === ");
        $finish;
    end
    
endmodule
