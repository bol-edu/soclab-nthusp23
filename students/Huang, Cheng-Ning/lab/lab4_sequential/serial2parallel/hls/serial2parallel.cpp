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
#include "serial2parallel.h"



void serial2parallel(bool serial_start, bool &end_conversion, bool d, ap_uint<N> &a) {

#pragma HLS INTERFACE ap_none port=serial_start
#pragma HLS INTERFACE ap_none port=end_conversion
#pragma HLS INTERFACE ap_none port=d
#pragma HLS INTERFACE ap_none port=a

#pragma HLS INTERFACE ap_ctrl_none port=return


	static ap_uint<N> state_reg = 0;
	static ap_uint<N> a_reg_out = 0;
	static unsigned int counter = N;


	unsigned int next_counter;
	ap_uint<N> next_state = state_reg;

	next_counter = counter;

	if (serial_start == 1) {
		next_counter = 0;
	}


	if (next_counter < N-1) {
		next_state = (next_state >> 1) | (d, (ap_uint<N-1>)0);;
		next_counter++;
		end_conversion = 0;
	} else if (next_counter == N-1) {
		next_state = (next_state >> 1) | (d, (ap_uint<N-1>)0);;
		next_counter++;
		a_reg_out = next_state;
		end_conversion = 1;
	} else {
		end_conversion = 0;
	}


	counter     = next_counter;
	state_reg   = next_state;
	a           = a_reg_out;
}
