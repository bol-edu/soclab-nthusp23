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
#include "uart_receiver.h"

typedef enum{idle, receive} uart_receive_states_type;

void uart_receiver (bool uart_rx, bool baud_rate_signal, ap_uint<8> &data, bool &valid_data) {
#pragma HLS INTERFACE ap_none port=valid_data
#pragma HLS INTERFACE ap_none port=data
#pragma HLS INTERFACE ap_none port=baud_rate_signal
#pragma HLS INTERFACE ap_none port=uart_rx
#pragma HLS INTERFACE ap_ctrl_none port=return


	static ap_uint<8> d;
	static unsigned int bit_counter = 0;
	static uart_receive_states_type state = idle;


	uart_receive_states_type next_state;
	unsigned int next_bit_counter ;

	bool stop_bit;
	bool valid_data_local = 0;



	switch(state) {
	case idle:
		if (baud_rate_signal == 1) {
			if (uart_rx == 0) {
				next_state =  receive;
			} else {
				next_state = idle;
			}
		} else {
			next_state = idle;
		}
		valid_data_local = 0;
		next_bit_counter = 0;
		break;
	case receive:
		if (baud_rate_signal == 1) {
			if (bit_counter == 8) {
				stop_bit = uart_rx;
				if (stop_bit == 1) {
					valid_data_local = 1;
				} else {
					valid_data_local = 0;
				}
				next_bit_counter = 0;
				next_state = idle;
			} else {
				d[bit_counter] = uart_rx;
				next_bit_counter = bit_counter+1;
				next_state = state;
				valid_data_local = 0;
			}
		} else {
			valid_data_local = 0;
			next_state = receive;
			next_bit_counter = bit_counter;
		}
		break;
	default:
		break;

	}

	state = next_state;
	bit_counter = next_bit_counter;
	data = d;
	valid_data = valid_data_local;
}
