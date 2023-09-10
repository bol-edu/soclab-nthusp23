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
#include "parallel2serial.h"


void parallel2serial(
		ap_uint<N> a,
		bool      &d,
		bool      &serial_start,
		bool      &serial_end,
		bool      begin)
{


#pragma HLS INTERFACE ap_none port=a
#pragma HLS INTERFACE ap_none port=d
#pragma HLS INTERFACE ap_none port=serial_start
#pragma HLS INTERFACE ap_none port=serial_end
#pragma HLS INTERFACE ap_none port=begin
#pragma HLS INTERFACE ap_ctrl_none port=return


	static int count = N;

	if (begin == 1) {
		count = 0;
	}

	if (count == 0) {
		serial_start = 1;
		serial_end   = 0;
		d = a[count++];
	} else if (count == N-1) {
		serial_start = 0;
		serial_end   = 1;
		d = a[count];
		count = N;
	} else if (count < N-1) {
		serial_start = 0;
		serial_end   = 0;
		d = a[count++];
	} else  {
		serial_start = 0;
		serial_end   = 0;
		count = N;
	}



}
