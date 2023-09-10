/************************************************
Copyright (c) 2021, Mohammad Hosseinabady
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
#include "parallel2serial-tb.h"


int main() {

	int status = 0;


	ap_uint<N> in_parallel = 0b11010011;
	bool       d;
	bool       serial_start;
	bool       serial_end;
	bool       begin;

	ap_uint<N> output;

	begin = 0;
	parallel2serial(in_parallel, d, serial_start, serial_end, begin);

	begin = 1;
	for (int i = 0; i < N; i++) {
		parallel2serial(in_parallel, d, serial_start, serial_end, begin);
		begin = 0;
		std::cout << " d = " << d << " serial_start = " << serial_start << " serial_end = " << serial_end << std::endl;
		output[i] = d;
	}

	if (in_parallel != output) {
		status = -1;
		std::cout << " Error = " << " in_parallel = " << in_parallel.to_string() << " output = " << output.to_string() <<std::endl;
	}

	if (status == 0) {
		std::cout << "Test Passed" << std::endl;
	} else {
		std::cout << "Test Failed" << std::endl;
	}

	return status;
}
