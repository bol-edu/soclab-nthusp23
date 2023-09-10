`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/21/2023 05:24:23 PM
// Design Name:
// Module Name: serial2parallel
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


module serial2parallel(clk,
                       rst_n,
                       serial_start,
                       serial_in,
                       parallel_out,
                       conversation_end,
                       );
    
    input clk;
    input rst_n;
    input serial_start;
    input serial_in;
    output reg [7:0] parallel_out;
    output reg conversation_end;
    
    reg [7:0] stage;
    reg [7:0] stage_next;
    
    reg [3:0] cnt;
    reg [3:0] cnt_next;
    
    
    //combnational logic
    always @(*)
    begin
        conversation_end = (cnt == 7);
        if (cnt == 8)
            parallel_out = stage;
        else
            parallel_out = {serial_in, 7'b0} | {stage >> 1};
            //counter
        if (serial_start)
        begin
            cnt_next   = 0;
            stage_next = {serial_in, 7'b0};
        end
        else if (cnt == 8)
        begin
            cnt_next   = cnt;
            stage_next = stage;
        end
        else
        begin
            cnt_next   = cnt + 1;
            stage_next = parallel_out;
        end
    end
    //sequential logic
    always @(posedge clk or negedge rst_n)
    begin
        if (!rst_n)
        begin
            cnt   <= 8;
            stage <= 0;
        end
        else
        begin
            cnt   <= cnt_next;
            stage <= stage_next;
        end
    end
    
endmodule
