#include "binary2bcd_double_dabble-tb.h"
#include <iostream>



int main() {
	int status = 0;

	uint8  in_binary = 47;
	uint16 unpacked_bcd;
	uint8 packed_bcd;



	binary2bcd_double_dabble(in_binary, &unpacked_bcd, &packed_bcd);


	std::cout << " in_binary = " << in_binary.to_string() << " unpacked_bcd = " << unpacked_bcd.to_string() << " packed_bcd = " << packed_bcd.to_string() << std::endl;


	return status;
}



