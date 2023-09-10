/************************************************
Copyright (c) 2021, Mohammad Hosseinabady
	mohammad@highlevel-synthesis.com.
	https://highlevel-synthesis.com/

All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. // Copyright (c) 2020, Mohammad Hosseinabady.
************************************************/
#include "vending_machine-tb.h"
#include <iostream>



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
