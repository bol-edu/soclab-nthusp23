#include "single_cycle_regular_pulses-tb.h"
#include <iostream>


int main() {

	int status = 0;

	bool periodic_pulses_local;
	std::cout <<  std::endl;
	std::cout <<  std::endl;

	for (int i = 0; i < 100; i++) {
		single_cycle_regular_pulses(periodic_pulses_local);
		std::cout << periodic_pulses_local ;
	}

	std::cout <<  std::endl;
	std::cout <<  std::endl;
	std::cout <<  std::endl;
	return status;
}


