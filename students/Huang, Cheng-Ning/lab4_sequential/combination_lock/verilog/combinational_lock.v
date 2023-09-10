`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/24/2023 09:01:50 PM
// Design Name:
// Module Name: combinational_lock
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

//the password is 2346

`define s0 3'd0
`define s2 3'd1
`define s23 3'd2
`define s234 3'd3
`define s2346 3'd4

`define SSD_0 8'b11000000
`define SSD_1 8'b11111001
`define SSD_2 8'b10100100
`define SSD_3 8'b10110000
`define SSD_4 8'b10011001
`define SSD_5 8'b10010010

module combinational_lock(clk,
                          rst_n,
                          num,
                          enter,
                          lock,
                          seven_segment_data,
                          seven_segment_enable,
                          door_open);
    input clk;
    input rst_n;
    input [3:0] num;//0~9
    input enter;
    input lock;
    output reg [7:0] seven_segment_data;
    output reg [3:0] seven_segment_enable;
    output reg door_open;
    
    reg [2:0] state;
    reg [2:0] next_state;
    
    //combinational logic
    always@(*)
    begin
        //door_open
        door_open = (state == `s2346);
        //FSM
        case(state)
            `s0:
            begin
                if (enter == 1)
                    if(num == 2)
                        next_state = `s2;
                    else
                        next_state = `s0;
                else
                    next_state = state;
            end
            `s2:
            begin
                if (enter == 1)
                    if(num == 3)
                        next_state = `s23;
                    else
                        next_state = `s0;
                else
                    next_state = state;
            end
            `s23:
            begin
                if (enter == 1)
                    if(num == 4)
                        next_state = `s234;
                    else
                        next_state = `s0;
                else
                    next_state = state;
            end
            `s234:
            begin
                if (enter == 1)
                    if(num == 6)
                        next_state = `s2346;
                    else
                        next_state = `s0;
                else
                    next_state = state;
            end
            `s2346:
            begin
                if (lock == 1)
                    next_state = `s0;
                else
                    next_state = state;
            end
            //this should not happen
            default:
                next_state = `s0;
        endcase
        //SSD enable
        seven_segment_enable = 4'b1110;
        //SSD for state
        case(state)
            `s0:
                seven_segment_data = `SSD_0;
            `s2:
                seven_segment_data = `SSD_1;
            `s23:
                seven_segment_data = `SSD_2;
            `s234:
                seven_segment_data = `SSD_3;
            `s2346:
                seven_segment_data = `SSD_4;
            default://this should not happen
                seven_segment_data = `SSD_5;
        endcase
    end
    //sequential logic
    always@(posedge clk or negedge rst_n)
    begin
        if (!rst_n)
            state <= `s0;
        else
            state <= next_state;
    end
        endmodule
