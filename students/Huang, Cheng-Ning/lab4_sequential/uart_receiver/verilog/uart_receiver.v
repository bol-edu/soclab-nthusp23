`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/28/2023 06:42:56 PM
// Design Name:
// Module Name: uart_receiver
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

/*
 * Input signals
 * `clk`: This signal is the clock signal.
 * `rst_n`: This signal is the active low reset signal.
 * `baud_rate_signal`: This signal is the baud rate signal.
 * `rx`: This signal represents the serial input data, encompassing the start signal, the input parallel data, and the stop signal.
 * Output signals
 * `data`: This signal represents the parallel data output.
 * `valid`: This signal represents the valid signal.*/

//define state
`define IDLE 1'b0
`define RECEIVE 1'b1

module uart_receiver(clk,
                     rst_n,
                     baud_rate_signal,
                     rx,
                     data,
                     valid);
    input clk;
    input rst_n;
    input baud_rate_signal;
    input rx;
    output reg [7:0] data;
    output reg valid;
    
    reg [7:0] next_data;
    reg next_valid;
    
    reg state;
    reg next_state;
    
    reg [3:0] cnt;
    reg [3:0] next_cnt;
    
    //combinational logic
    always @ (*)
    begin
        if (baud_rate_signal == 1'b1)
            case(state)
                `IDLE:
                begin
                    if (rx == 1'b0)
                    begin
                        next_valid = 1'b0;
                        next_data  = data;
                        next_state = `RECEIVE;
                        next_cnt   = 4'd0;
                    end
                    else
                    begin
                        next_valid = 1'b0;
                        next_data  = data;
                        next_state = `IDLE;
                        next_cnt   = cnt + 1;
                    end
                end
                `RECEIVE:
                begin
                    if (cnt == 4'd9)
                    begin
                        next_valid = 1'b1;
                        next_data  = data;
                        next_state = `IDLE;
                        next_cnt   = cnt + 1;
                    end
                    else
                    begin
                        next_valid     = 1'b0;
                        next_data = data;
                        next_data[cnt] = rx;
                        next_state     = `RECEIVE;
                        next_cnt       = cnt + 1;
                    end
                end
                default://should not happen
                begin
                    next_valid = valid;
                    next_data  = data;
                    next_state = `IDLE;
                    next_cnt   = 4'd0;
                end
            endcase
        else
        begin
            next_valid = valid;
            next_data  = data;
            next_state = state;
            next_cnt   = cnt;
        end
    end
    
    //sequential logic
    always @ (posedge clk or negedge rst_n)
    begin
        if (!rst_n)
        begin
            data  <= 8'b0;
            valid <= 1'b0;
            state <= `IDLE;
            cnt   <= 4'b0000;
        end
        else
        begin
            data  <= next_data;
            valid <= next_valid;
            state <= next_state;
            cnt   <= next_cnt;
        end
    end
endmodule
