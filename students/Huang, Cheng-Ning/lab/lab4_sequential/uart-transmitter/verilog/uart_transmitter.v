`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/28/2023 11:52:16 AM
// Design Name:
// Module Name: uart_transmitter
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

/** Input signals
  * `clk`: This signal is the clock signal.
  * `rst_n`: This signal is the active low reset signal.
  * `baud_rate_signal`: This signal is the baud rate signal.
  * `data`: This signal is the parallel input data.
  * `start`: This signal instructs the transmitter to initiate the data transmission process.
* Output signals
  * `tx`: This signal represents the serial output data, encompassing the start signal, the input parallel data, and the stop signal.
*/

//define states
`define IDLE 1'b0
`define TRANSMIT 1'b1

module uart_transmitter(clk, rst_n, baud_rate_signal, data_in, start, tx);
    input clk;
    input rst_n;
    input baud_rate_signal;
    input [7:0] data_in;
    input start;
    output reg tx;

    reg state;
    reg next_state;
    reg [3:0] cnt;
    reg [3:0] next_cnt;

    //combinational logic
    always@ (*)
    begin
        case(state)
            `IDLE:
            begin
                if(start == 1'b1)
                begin
                    tx = 0;
                    next_state = `TRANSMIT;
                    next_cnt = 4'b0000;
                end
                else
                begin
                    tx = 1;
                    next_state = `IDLE;
                    next_cnt = cnt + 1;
                end
            end
            `TRANSMIT:
            begin
                if(cnt == 0)
                begin
                    tx = 0;
                    next_state = `TRANSMIT;
                    next_cnt = cnt + 1;
                end
                else if(cnt == 4'd9)//stop bit
                begin
                    tx = 1;
                    next_state = `IDLE;
                    next_cnt = cnt + 1;
                end
                else
                begin
                    tx = data_in[cnt-1];
                    next_state = `TRANSMIT;
                    next_cnt = cnt + 1;
                end
            end
        endcase
    end

    //sequential logic
    always@(posedge clk or negedge rst_n)
    begin
        if(!rst_n)
        begin
            state <= `IDLE;
            cnt <= 4'd0;
        end
        else if (baud_rate_signal == 1)
        begin
            state <= next_state;
            cnt <= next_cnt;
        end
        else
        begin
            state <= state;
            cnt <= cnt;
        end
    end
endmodule
