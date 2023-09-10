#include "one_digit_bcd_counter-tb.h"
#include <iostream>



int main() {
	int status = 0;

	bool pulse;
	ap_uint<8> seven_segment_data_hw;
	ap_uint<4> seven_segment_enable_hw;

	ap_uint<8> seven_segment_data_sw;
	ap_uint<4> seven_segment_enable_sw;


	for (int i = 0; i < 12; i++) {
		bcd_counter(1, seven_segment_data_hw, seven_segment_enable_hw);
	}


	if (status == 0) {
		std::cout << "Test Passed!" << std::endl;
	} else {
		std::cout << "Test Failed!" << std::endl;
	}


	return status;

}
