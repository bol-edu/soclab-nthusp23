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
#include "iir-tb.h"



void iir_golden(DATA_TYPE *x, DATA_TYPE *y, int n) {


	y[0] = b0*x[0];
	y[1] = b0*x[1]+b1*x[0]-a1*y[0];

	for (int i = 2; i < n; i++) {
		y[i] = b0*x[i]+b1*x[i-1]+b2*x[i-2]-a1*y[i-1]-a2*y[i-2];
	}

}


int main() {

	int status = 0;

	DATA_TYPE x[N] = {1, 2, 3, 4, 5, 6, 7, 8};
	DATA_TYPE y_hw[N] = {0};
	DATA_TYPE y_golden[N] = {0};

	for (int i = 0; i < N; i++) {
		iir(x[i], y_hw[i]);
		std::cout << "y_hw[" << i <<"] = " << y_hw[i] << std::endl;
	}

	iir_golden(x, y_golden, N);


	for (int i = 0; i < N; i++) {
		if (y_hw[i]  != y_golden[i]) {
			status = -1;
			std::cout << " Error at " << i
					  <<  " y_hw[" << i <<"] = " << y_hw[i]
					<<  " y_golden[" << i <<"] = " << y_golden[i]
														 << std::endl;
			break;
		}
	}

	if(status == 0) {
		std::cout << "Test Passed! " << std::endl;
	} else {
		std::cout << "Test Failed! " << std::endl;
	}

	return status;

}


