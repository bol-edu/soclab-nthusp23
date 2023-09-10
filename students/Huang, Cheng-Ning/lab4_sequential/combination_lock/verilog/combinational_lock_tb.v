`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/24/2023 11:38:08 PM
// Design Name:
// Module Name: combinational_lock_tb
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


module combinational_lock_tb();
    reg clk;
    reg rst_n;
    reg [3:0] num;//0~9
    reg enter;
    reg lock;
    wire [7:0] seven_segment_data;
    wire [3:0] seven_segment_enable;
    wire door_open;

    combinational_lock combinational_lock(.clk(clk),
                                          .rst_n(rst_n),
                                          .num(num),
                                          .enter(enter),
                                          .lock(lock),
                                          .seven_segment_data(seven_segment_data),
                                          .seven_segment_enable(seven_segment_enable),
                                          .door_open(door_open));
    
    always @ #10 clk = ~clk;
    
    initial begin
        clk = 1;
        rst_n = 1;
        num = 0;
        enter = 0;
        lock = 0;
        #90 rst_n = 0;
        #10 rst_n = 1;
        #20 num = 1; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 2; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 3; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 1; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 2; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 3; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 4; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 6; enter = 0;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 6; enter = 0;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 6; enter = 0;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %d", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 6; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %b, door_open = %b", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 1; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %d, door_open = %b", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 2; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %d, door_open = %b", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 2; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %d, door_open = %b", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 2; enter = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %d, door_open = %b", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 2; enter = 1; lock = 1;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %d, door_open = %b", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
        #20 num = 2; enter = 1; lock = 0;
        $display("num = %d, enter = %d, lock = %d, seven_segment_data = %b, seven_segment_enable = %d, door_open = %b", num, enter, lock, seven_segment_data, seven_segment_enable, door_open);
        //------------------------------------------------------------------------------
    end

endmodule
