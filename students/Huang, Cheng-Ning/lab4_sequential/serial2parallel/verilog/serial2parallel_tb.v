`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/21/2023 06:24:11 PM
// Design Name:
// Module Name: serial2parallel_tb
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


module serial2parallel_tb();
    
    reg clk;
    reg rst_n;
    reg serial_start;
    reg serial_in;
    wire [7:0] parallel_out;
    wire conversation_end;
    reg [7:0] data = 8'b01001101;
    
    serial2parallel serial2parallel_0(.clk(clk),
    .rst_n(rst_n),
    .serial_start(serial_start),
    .serial_in(serial_in),
    .parallel_out(parallel_out),
    .conversation_end(conversation_end));
    
    always #10 clk = ~clk;
    
    initial begin
        clk = 1;
        serial_start = 0;
        serial_in = 0;
        rst_n = 1;
        $display("=== Initial Success ===");
        #90 rst_n = 0;
        #10 rst_n = 1;
        #100 serial_start = 1;
        for(integer i = 0; i < 8; i = i + 1)
        begin
            @(posedge clk) serial_in = data[i];
            #20 serial_start = 0;
        end
        #100 $display("=== Simulation Success ===");
        $display("parallel_out = %b", parallel_out);

        if(parallel_out == 8'b01001101)
            $display("=== Test Success ===");
        else
            $display("=== Test Failed ===");
        $finish;
    end
endmodule
