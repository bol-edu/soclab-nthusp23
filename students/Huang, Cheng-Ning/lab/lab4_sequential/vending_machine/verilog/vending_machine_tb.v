`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 08/25/2023 04:04:31 PM
// Design Name:
// Module Name: vending_machine_tb
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
testbench in cpp, rewrite it in verilog:
void put_coin(
		bool nickel_in,
		bool dime_in,
		bool quarter_in)
{
	bool       candy_out;
	bool       nickel_out;
	ap_uint<2> dime_out;
	bool       thanks_in;

	vending_machine( nickel_in,	dime_in, quarter_in, thanks_in, candy_out, nickel_out,	dime_out);
	std::cout << " nickel_in = " << nickel_in << " dime_in = " << dime_in << " quarter_in = " << quarter_in << " | ";
	std::cout << " candy_out = " << candy_out << " nickel_out = " << nickel_out << " dime_out = " << dime_out.to_string() << std::endl;

	nickel_in = 0;	dime_in = 0; quarter_in = 0; thanks_in=0;
	int n = rand() % 10+2;
	for (int i = 0; i < n; i++) {
		vending_machine( nickel_in,	dime_in, quarter_in, thanks_in, candy_out, nickel_out,	dime_out);
		std::cout << " nickel_in = " << nickel_in << " dime_in = " << dime_in << " quarter_in = " << quarter_in << " | ";
		std::cout << " candy_out = " << candy_out << " nickel_out = " << nickel_out << " dime_out = " << dime_out.to_string() << std::endl;
	}
}


int main() {

	int status = 0;
	bool       nickel_in;
	bool       dime_in;
	bool       quarter_in;
	bool       candy_out;
	bool       nickel_out;
	ap_uint<2> dime_out;
	bool       thanks_in;



	put_coin(0, 0, 0); // no coin
	put_coin(0, 1, 0); // dime
	put_coin(0, 1, 0); // dime
	put_coin(0, 0, 1); // quarter




	return status;
}

*/

module vending_machine_tb();
    
    reg clk;
    reg rst_n;
    reg nickel_in;
    reg dime_in;
    reg quarter_in;
    reg thanks_in;
    wire candy_out;
    wire nickel_out;
    wire [1:0] dime_out;

    vending_machine vending_machine(clk,
                                    rst_n,
                                    nickel_in,
                                    dime_in,
                                    quarter_in,
                                    thanks_in,
                                    candy_out,
                                    nickel_out,
                                    dime_out);
    
    always #10 clk = ~clk;

    task put_coin;
        input nickel_in_task;
        input dime_in_task;
        input quarter_task;

        begin
            #20
            nickel_in = nickel_in_task;
            dime_in = dime_in_task;
            quarter_in = quarter_task;
            #20
            nickel_in = 0;
            dime_in = 0;
            quarter_in = 0;
        end
    endtask

    initial
    begin
        clk = 1;
        rst_n = 1;
        nickel_in = 0;
        dime_in = 0;
        quarter_in = 0;
        thanks_in = 0;

        #90 rst_n = 0;
        #10 rst_n = 1;

        #10
        put_coin(0, 0, 0); // no coin
        put_coin(0, 1, 0); // dime
        put_coin(0, 1, 0); // dime
        put_coin(0, 0, 1); // quarter

        $finish;
    end
endmodule
