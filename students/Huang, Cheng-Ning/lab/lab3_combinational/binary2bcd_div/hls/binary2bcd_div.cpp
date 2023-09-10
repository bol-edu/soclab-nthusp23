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
#include "binary2bcd_div.h"


void get_digit(uint14 &a, uint4 &digit) {
	digit = a-10*(a/10);
	a = a/10;
}


void binary2bcd_div(uint14 in_binary, uint16 *packed_bcd) {
#pragma HLS INTERFACE ap_none port=in_binary
#pragma HLS INTERFACE ap_none port=unpacked_bcd
#pragma HLS INTERFACE ap_none port=packed_bcd
#pragma HLS INTERFACE ap_ctrl_none port=return


	uint14 a = in_binary;

	uint4 digit_1;
	uint4 digit_2;
	uint4 digit_3;
	uint4 digit_4;


	get_digit (a, digit_1);
	get_digit (a, digit_2);
	get_digit (a, digit_3);
	get_digit (a, digit_4);

	*packed_bcd   = (digit_4, digit_3, digit_2,  digit_1);

}
