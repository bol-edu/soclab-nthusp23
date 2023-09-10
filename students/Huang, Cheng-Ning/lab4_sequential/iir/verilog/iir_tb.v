`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/26/2023 12:16:16 PM
// Design Name:
// Module Name: iir_tb
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

module iir_tb();

    reg clk;
    reg rst_n;
    reg signed [31:0] x [0:7];
    reg signed [31:0] x_in;
    reg signed [31:0] y [0:7];
    wire signed [31:0] y_out;

    //golden model
    reg signed [31:0] y_golden [0:7];
    reg [255:0] y_packed;
    reg [255:0] x_packed;

    integer i;

    //instantiate the unit under test (UUT)
    iir iir_0 (
        .clk(clk),
        .rst_n(rst_n),
        .x(x_in),
        .y(y_out)
    );

    task iir_golden;
        input [255:0] x_packed;
        output [255:0] y_golden_packed;

        reg signed [31:0] x [0:7];
        reg signed [31:0] y [0:7];

        integer i;
        begin
            for(i = 0; i < 8; i = i + 1)
                x[i] = x_packed[32*i +: 32];

            //y = 6x + (x-1) + 2(x-2) - 4(y-1) - 3(y-2)
            y[0] = 6 * x[0];
            y[1] = 6 * x[1] + x[0] - 4 * y[0];
            for(i = 2; i < 8; i = i + 1)
                y[i] = 6 * x[i] + x[i-1] + 2 * x[i-2] - 4 * y[i-1] - 3 * y[i-2];
        
            //pack the output
            for (i = 0; i < 8; i = i + 1)
                y_golden_packed[32*i +: 32] = y[i];
        end
    endtask

    //clock generator
    always #10 clk <= ~clk;

    initial begin
        // Initialize Inputs
        clk = 0;
        rst_n = 1;
        x_in = 0;
        for(i=0; i<8; i=i+1)
            x[i] = i+1;
        y[0] = 0;
        y_golden[0] = 0;

        //golden model
        for(i=0; i<8; i=i+1)
            x_packed[32*i +: 32] = x[i];

        iir_golden(x_packed, y_packed);

        for(i=0; i<8; i=i+1)
            y_golden[i] = y_packed[32*i +: 32];

        #90 rst_n = 0;
        #10 rst_n = 1;

        for(i=0; i<8; i=i+1)
        begin
            @(posedge clk) x_in <= x[i];
            #1 y[i] = y_out;
        end

        //compare with golden model
        for(i=0; i<8; i=i+1)
        begin
            if(y[i] != y_golden[i])
                $display("y[%0d] = %d, y_golden[%0d] = %d", i, y[i], i, y_golden[i]);
        end
    end
 

    
endmodule
