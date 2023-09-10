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
#include "combination_lock.h"

typedef enum {s0, s2, s23, s234, s2346} state_type;


ap_uint<8> get_seven_segment_code(state_type number) {
#pragma HLS INLINE

	ap_uint<8> code = seven_segment_code[0];
	switch(number) {

	case s0:
		code = seven_segment_code[0];
		break;
	case s2:
		code = seven_segment_code[1];
		break;
	case s23:
		code = seven_segment_code[2];
		break;
	case s234:
		code = seven_segment_code[3];
		break;
	case s2346:
		code = seven_segment_code[4];
		break;
	default:
		break;
	}

	return code;
}






void combination_lock(
		ap_uint<4> x,
		bool enter,
		bool &door_open,
		bool lock,
		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable) {
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_none port=x
#pragma HLS INTERFACE ap_none port=enter
#pragma HLS INTERFACE ap_none port=door_open
#pragma HLS INTERFACE ap_none port=lock
#pragma HLS INTERFACE ap_none port=seven_segment_data
#pragma HLS INTERFACE ap_none port=seven_segment_enable
#pragma HLS INTERFACE ap_ctrl_none port=return



//--------state variables-----------------------------
	static state_type state = s0;

	state_type next_state;

//--------temporary output variables------------------
	bool door_open_local = 0;


//--------switch case---------------------------------
	switch(state) {
	case s0:
		if (enter == 1) {
			if (x == 2) {
				next_state = s2;
			} else {
				next_state = s0;
			}
		} else {
			next_state = s0;
		}
		door_open_local = 0;
		break;
	case s2:
		if (enter == 1) {
			if (x == 3) {
				next_state = s23;
			} else {
				next_state = s0;
			}
		 } else {
			 next_state = s2;
		 }
		door_open_local = 0;
		break;
	case s23:
		if (enter == 1) {
			if (x == 4) {
				next_state = s234;
			} else {
				next_state = s0;
			}
		} else {
			next_state = s23;
		}
		door_open_local = 0;
		break;
	case s234:
		if (enter == 1) {
			if (x == 6) {
				next_state = s2346;
				door_open_local = 1;
			} else {
				next_state = s0;
				door_open_local = 0;
			}
		 } else {
			 next_state = s234;
			 door_open_local = 0;
		 }

		break;
	case s2346:
		if (lock == 1) {
			next_state = s0;
			door_open_local = 0;
		} else {
			next_state = s2346;
			door_open_local = 1;
		}

		break;
	default:
		break;
	}

//--------state and output variable assignments------------
	state = next_state;
	door_open = door_open_local;

	seven_segment_data = get_seven_segment_code(state);
	seven_segment_enable = 0b1110;
}
