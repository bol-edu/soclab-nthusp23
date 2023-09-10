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
#include "serial2parallel-tb.h"


int main() {
	int status = 0;

	ap_uint<N> data = 0b1001101;
	ap_uint<N> a;
	bool start_serial_data;
	bool end_conversion;
	bool d;


	std::cout << std::endl;;
	start_serial_data = 0;
	serial2parallel(start_serial_data, end_conversion, d, a);



	start_serial_data = 1;
	for (int i = 0; i <200; i++) {
		d = data[i];
		serial2parallel(start_serial_data, end_conversion, d, a);
		start_serial_data = 0;
		if (end_conversion == 1) {
			std::cout << a.to_string() << std::endl;
			break;
		}
	}

	if (data != a) {
		status = -1;
		std::cout << " data = " << data.to_string() << " a = " << a.to_string() <<std::endl;
	}


	if (status == 0) {
		std::cout << "Test Passed" << std::endl;
	} else {
		std::cout << "Test Failed" << std::endl;
	}

	return status;

}
