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
#include "binary2bcd_div-tb.h"
#include <iostream>

void binary2bcd_software(uint14 in_binary, uint16 *packed_bcd) {

	int packed_bcd_tmp;
	int in_binary_tmp = in_binary;

	if (in_binary == 100) {
		std::cout << std::endl;
	}

	int r = in_binary_tmp%10;
	packed_bcd_tmp = r;
	in_binary_tmp = in_binary_tmp/10;

	r = in_binary_tmp%10;
	packed_bcd_tmp = r*0b10000 + packed_bcd_tmp;
	in_binary_tmp = in_binary_tmp/10;

	r = in_binary_tmp%10;
	packed_bcd_tmp = r*0b100000000 + packed_bcd_tmp;
	in_binary_tmp = in_binary_tmp/10;

	r = in_binary_tmp%10;
	packed_bcd_tmp = r*0b1000000000000 + packed_bcd_tmp;

	*packed_bcd = packed_bcd_tmp;
}

int main() {
	int status = 0;

	uint14 in_binary = 9999;

	uint16 packed_bcd_hw;
	uint16 packed_bcd_sw;

	for (int i = 0; i < 9999; i++) {
		in_binary = (uint14)i;
		binary2bcd_div(in_binary, &packed_bcd_hw);
		binary2bcd_software(in_binary, &packed_bcd_sw);

		if (packed_bcd_hw !=packed_bcd_sw) {
			status = -1;
			std::cout << "Error at " << i << "  in_binary = " << in_binary.to_string()
					  << " packed_bcd_hw = " << packed_bcd_hw.to_string()
					  << " packed_bcd_sw = " << packed_bcd_sw.to_string()
					  << std::endl;
			break;
		}
	}



	if (status == 0) {
		std::cout << " Test Passed!" << std::endl;
	} else {
		std::cout << " Test Failed!" << std::endl;
	}

	return status;
}



