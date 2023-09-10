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
#include "uart_transmitter.h"

typedef enum{idle, transmit} uart_transmit_states_type;

void uart_transmitter(bool &uart_tx, ap_uint<8> data, bool baud_rate_signal, bool start) {
#pragma HLS INTERFACE ap_none port=data
#pragma HLS INTERFACE ap_none port=baud_rate_signal
#pragma HLS INTERFACE ap_none port=uart_tx
#pragma HLS INTERFACE ap_none port=start
#pragma HLS INTERFACE ap_ctrl_none port=return


	ap_uint<10> d = ((bool)0b1, (ap_int<8>)data, (bool)0b0);


	static unsigned int              bit_counter = 0;
	static uart_transmit_states_type state = idle;


	uart_transmit_states_type next_state;
	unsigned int              next_bit_counter;
	bool uart_tx_local;


	switch(state) {
	case idle:
		if ( start == 1) {
			next_state = transmit;
			uart_tx_local      = 1;
			next_bit_counter   = 0;
		} else {
			next_state = idle;
			uart_tx_local      = 1;
			next_bit_counter   = 0;
		}

		break;
	case transmit:
		if (baud_rate_signal == 1) {
			if (bit_counter == 10) {
				next_state        = idle;
				uart_tx_local     = 1;
				next_bit_counter  = 0;
			} else  {
				next_state       =  transmit;
				uart_tx_local    =  d[bit_counter];
				next_bit_counter =  bit_counter+1;
			}
		} else {
			if (bit_counter == 0) {
				uart_tx_local    =  1;
			} else {
				uart_tx_local    =  d[bit_counter-1];
			}
			next_state       =  transmit;
			next_bit_counter =  bit_counter;
		}

		break;

	default:
		break;
	}


	state                     = next_state;
	bit_counter               = next_bit_counter;
	uart_tx                   = uart_tx_local;

}
