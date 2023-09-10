/************************************************
Copyright (c) 2020, Mohammad Hosseinabady
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
#include "leading_one-tb.h"
#include <iostream>



int find_leading_one_golden(int a) {
	int r;

	if (a == 0)
		r = -1;
	if (a > 0 && a < 2)
		r = 0;
	if (a > 1 && a < 4)
		r = 1;
	if (a > 3 && a < 8)
		r = 2;
	if (a > 7 && a < 16)
		r = 3;
	if (a > 15 && a < 32)
		r = 4;
	if (a > 31 && a < 64)
		r = 5;
	if (a > 63 && a < 128)
		r = 6;
	if (a > 127 && a < 256)
		r = 7;
	if (a > 255 && a < 512)
			r = 8;

	return r;
}



int main() {
	int status = 0;


	for (int i = 0; i < 512; i++) {

		int        index_gold = find_leading_one_golden(i);
		ap_int<9> a = (ap_int<9>)i;
		ap_int<5> index = leading_one(a);

		if (index != index_gold) {
			status = -1;
			std::cout << "number = " << i << " index_gold = " << index_gold << " index = " << index << std::endl;
			std::cout << "number = " << a.to_string() << " leading one at " << index << std::endl;

		} else {
			std::cout << "number = " << a.to_string() << " leading one at " << index << std::endl;
		}


	}


	if (status == 0) {
		std::cout << "Test passed! " << std::endl;
	} else {
		std::cout << "Test failed! " << std::endl;
	}

	return status;
}
