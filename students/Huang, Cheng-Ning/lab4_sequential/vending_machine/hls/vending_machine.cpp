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
#include "vending_machine.h"

typedef  enum states{st0, st5, st10, st15, st20, st25, st30, st35, st40, st45, swait} state_type;


void vending_machine(
	bool        nickel_in,
	bool        dime_in,
	bool        quarter_in,

	bool        thanks_in,

	bool       &candy_out,
	bool       &nickel_out,
	ap_uint<2> &dime_out)
{

#pragma HLS INTERFACE ap_none port=nickel_in
#pragma HLS INTERFACE ap_none port=dime_in
#pragma HLS INTERFACE ap_none port=quarter_in

#pragma HLS INTERFACE ap_none  port=thanks_in


#pragma HLS INTERFACE ap_none  port=candy_out
#pragma HLS INTERFACE ap_none  port=nickel_out
#pragma HLS INTERFACE ap_none  port=dime_out

#pragma HLS INTERFACE ap_ctrl_none port=return




	static state_type s;

	state_type s_next = s;

	bool       candy_out_local;
	bool       nickel_out_local;
	ap_uint<2> dime_out_local;


	switch(s) {
	case st0:
		candy_out_local  = 0;
		nickel_out_local = 0;
		dime_out_local   = 0b00;
		if (nickel_in)
			s_next = st5;
		else if (dime_in)
			s_next = st10;
		else if (quarter_in)
			s_next = st25;
		else
			s_next = st0;
		break;
	case st5:
		candy_out_local  = 0;
		nickel_out_local = 0;
		dime_out_local   = 0b00;
		if (nickel_in)
			s_next = st10;
		else if (dime_in)
			s_next = st15;
		else if (quarter_in)
			s_next = st30;
		else
			s_next = st5;
		break;
	case st10:
		candy_out_local  = 0;
		nickel_out_local = 0;
		dime_out_local   = 0b00;
		if (nickel_in)
			s_next = st15;
		else if(dime_in)
			s_next = st20;
		else if (quarter_in)
			s_next = st35;
		else
			s_next = st10;
		break;
	case st15:
		candy_out_local  = 0;
		nickel_out_local = 0;
		dime_out_local   = 0b00;
		if (nickel_in)
			s_next = st20;
		else if (dime_in)
			s_next = st25;
		else if (quarter_in)
			s_next = st40;
		else
			s_next = st15;
		break;
	case st20:
		candy_out_local  = 0;
		nickel_out_local = 0;
		dime_out_local   = 0b00;
		if (nickel_in)
			s_next = st25;
		else if (dime_in)
			s_next = st30;
		else if (quarter_in)
			s_next = st45;
		else
			s_next = st20;
		break;
	case st25:
		candy_out_local  = 1;
		nickel_out_local = 0;
		dime_out_local   = 0b00;
		s_next = swait;
		break;
	case st30:
		candy_out_local  = 1;
		nickel_out_local = 1;
		dime_out_local   = 0b00;
		s_next = swait;
		break;
	case st35:
		candy_out_local  = 1;
		nickel_out_local = 0;
		dime_out_local   = 0b01;
		s_next = swait;
		break;
	case st40:
		candy_out_local  = 1;
		nickel_out_local = 1;
		dime_out_local   = 0b01;
		s_next = swait;
		break;
	case st45:
		candy_out_local  = 1;
		nickel_out_local = 0;
		dime_out_local   = 0b11;
		s_next = swait;
		break;
	case swait:
		candy_out_local  = 0;
		nickel_out_local = 0;
		dime_out_local   = 0b00;
		if (thanks_in == 1)
			s_next = st0;
		else
			s_next = swait;
		break;
	default:
		break;
	}

	s = s_next;
	candy_out  = candy_out_local;
	nickel_out = nickel_out_local;
	dime_out   = dime_out_local;

}
