`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/22/2023 11:37:09 PM
// Design Name:
// Module Name: parallel2serial_tb
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


module parallel2serial_tb();
    reg clk;
    reg in_begin;
    reg[7:0] parallel_in;
    wire serial_start;
    wire serial_out;
    wire serial_end;
    
    parallel2serial parallel2serial_0 (
    .clk(clk),
    .in_begin(in_begin),
    .parallel_in(parallel_in),
    .serial_start(serial_start),
    .serial_out(serial_out),
    .serial_end(serial_end)
    );
    
    always #10 clk = ~clk;
    
    initial begin
        clk                     = 1;
        in_begin                = 0;
        parallel_in             = 8'b11010011;
        
        #80 in_begin = 1;
        #20 in_begin = 0;

    end
    
    always @(*)
    begin
        @(posedge clk) $display("serial_start = %b, serial_out = %b, serial_end = %b", serial_start, serial_out, serial_end);
    end
    
endmodule
