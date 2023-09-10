#include "one_digit_bcd_counter.h"


void bcd_counter(bool pulse, ap_uint<8> &seven_segment_data, ap_uint<4> &seven_segment_enable) {

#pragma HLS INTERFACE ap_none port=seven_segment_enable
#pragma HLS INTERFACE ap_none port=seven_segment_data
#pragma HLS INTERFACE ap_none port=pulse
#pragma HLS INTERFACE ap_ctrl_hs port=return


	static ap_uint<4> counter_state = 0;

	if (pulse == 1){
		if (counter_state == 9)
			counter_state = 0;
		else
			counter_state++;
	}

	seven_segment_data = seven_segment_code[counter_state];
	seven_segment_enable = 0b1110;


}
