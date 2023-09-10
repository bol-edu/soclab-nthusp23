`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/25/2023 03:49:33 PM
// Design Name:
// Module Name: vending_machine
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

//define states st0, st5, st10, st15, st20, st25, st30, st35, st40, st45, swait
//the state name means the amount of money in the machine
`define st0 4'b0000
`define st5 4'b0001
`define st10 4'b0010
`define st15 4'b0011
`define st20 4'b0100
`define st25 4'b0101
`define st30 4'b0110
`define st35 4'b0111
`define st40 4'b1000
`define st45 4'b1001
`define swait 4'b1010

/*
The objective of this design is to create a vending machine 
that dispenses candy priced at twenty-five cents. 
This vending machine accommodates nickels, dimes, and quarters
as acceptable coins. Upon the user inserting the appropriate 
amount of money, the machine dispenses the candy and returns
any surplus change. Subsequently, once the user takes the
candy, the machine transitions into a waiting state, ready
for the next purchase.

* Input Signals:
 * **clk**: This signal is the clock input.
 * **rst_n**: This signal is a low-active reset trigger.
 * **nickel_in**: This signal represents the nickel input.
 * **dime_in**: This signal represents the dime input.
 * **quarter_in**: This signal represents the quarter input.
 * **thanks_in**: This signal represents the user taking the candy.
 * Output Signals:
 * **candy_out**: This signal represents the candy output.
 * **nickel_out**: This signal represents the nickel output.
 * **dime_out[0]**: This signal represents the dime output.
 * **dime_out[1]**: This signal represents the other dime output.*/

module vending_machine(clk,
                       rst_n,
                       nickel_in,
                       dime_in,
                       quarter_in,
                       thanks_in,
                       candy_out,
                       nickel_out,
                       dime_out);
    
    input clk;
    input rst_n;
    input nickel_in;
    input dime_in;
    input quarter_in;
    input thanks_in;
    output reg candy_out;
    output reg nickel_out;
    output reg [1:0] dime_out;

    reg [3:0] state;
    reg [3:0] next_state;

    //combinational logic
    always @(*)
    begin
        case(state)
            //waiting for money
            `st0:
            begin
                //output
                candy_out = 1'b0;
                nickel_out = 1'b0;
                dime_out = 2'b00;
                //next_state
                if(nickel_in)
                    next_state = `st5;
                else if(dime_in)
                    next_state = `st10;
                else if(quarter_in)
                    next_state = `st25;
                else
                    next_state = `st0;
            end
            `st5:
            begin
                //output
                candy_out = 1'b0;
                nickel_out = 1'b0;
                dime_out = 2'b00;
                //next_state
                if(nickel_in)
                    next_state = `st10;
                else if(dime_in)
                    next_state = `st15;
                else if(quarter_in)
                    next_state = `st30;
                else
                    next_state = `st5;
            end
            `st10:
            begin
                //output
                candy_out = 1'b0;
                nickel_out = 1'b0;
                dime_out = 2'b00;
                //next_state
                if(nickel_in)
                    next_state = `st15;
                else if(dime_in)
                    next_state = `st20;
                else if(quarter_in)
                    next_state = `st35;
                else
                    next_state = `st10;
            end
            `st15:
            begin
                //output
                candy_out = 1'b0;
                nickel_out = 1'b0;
                dime_out = 2'b00;
                //next_state
                if(nickel_in)
                    next_state = `st20;
                else if(dime_in)
                    next_state = `st25;
                else if(quarter_in)
                    next_state = `st40;
                else
                    next_state = `st15;
            end
            `st20:
            begin
                //output
                candy_out = 1'b0;
                nickel_out = 1'b0;
                dime_out = 2'b00;
                //next_state
                if(nickel_in)
                    next_state = `st25;
                else if(dime_in)
                    next_state = `st30;
                else if(quarter_in)
                    next_state = `st45;
                else
                    next_state = `st20;
            end
            //candy is dispensed and charge is returned
            `st25:
            begin
                //output
                candy_out = 1'b1;
                nickel_out = 1'b0;
                dime_out = 2'b00;
                //next_state
                next_state = `swait;
            end
            `st30:
            begin
                //output
                candy_out = 1'b1;
                nickel_out = 1'b1;
                dime_out = 2'b00;
                //next_state
                next_state = `swait;
            end
            `st35:
            begin
                //output
                candy_out = 1'b1;
                nickel_out = 1'b0;
                dime_out = 2'b01;
                //next_state
                next_state = `swait;
            end
            `st40:
            begin
                //output
                candy_out = 1'b1;
                nickel_out = 1'b1;
                dime_out = 2'b01;
                //next_state
                next_state = `swait;
            end
            `st45:
            begin
                //output
                candy_out = 1'b1;
                nickel_out = 1'b0;
                dime_out = 2'b11;
                //next_state
                next_state = `swait;
            end
            //waiting for user to take candy
            `swait:
            begin
                //output
                candy_out = 1'b0;
                nickel_out = 1'b0;
                dime_out = 2'b00;
                //next_state
                if(thanks_in)
                    next_state = `st0;
                else
                    next_state = `swait;
            end
            default://should never happen
            begin
                //output
                candy_out = 1'b0;
                nickel_out = 1'b0;
                dime_out = 2'b00;
                //next_state
                next_state = `st0;
            end
        endcase
    end
    //sequential logic
    always @(posedge clk or negedge rst_n)
    begin
        if(!rst_n)
            state <= `st0;
        else
            state <= next_state;
    end
endmodule
