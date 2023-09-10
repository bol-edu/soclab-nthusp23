#include "parity_generator-tb.h"
#include <iostream>
#include <bitset>


bool parity_generator_sw(ap_uint<W> a) {
	bool parity = 0;

	for (int i = 0; i < W; i++) {
		parity = parity ^ a[i];
	}

	return parity;
}

int main() {
	int status = 0;


	ap_uint<W> x;




	bool parity_hw;
	bool parity_sw;

	for (int i = 0; i < 65536; i++) {
		x = (ap_uint<W>)i;
		parity_hw = parity_generator(x);
		parity_sw = parity_generator_sw(x);

		if (parity_sw != parity_hw)
		{
			status = -1;
			std::cout << "x = " << std::bitset<W>(x) << "  parity_hw = " << parity_hw << "  parity_sw = " << parity_sw <<std::endl;
			break;
		}
//		std::cout << "x = " << std::bitset<W>(x) << "  parity_hw = " << parity_hw << "  parity_sw = " << parity_sw <<std::endl;
	}



	if (status == 0) {
		std::cout << "Test Successful!" << std::endl;
	} else {
		std::cout << "Test Failed!" << std::endl;
	}


	return status;
}
