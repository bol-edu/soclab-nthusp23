#include "single_cycle_regular_pulses.h"




#define PULSE_PERIOD 20

typedef enum{zero, one} states_type;
void single_cycle_regular_pulses(bool &periodic_pulses) {
#pragma HLS INTERFACE ap_none port=periodic_pulses
#pragma HLS INTERFACE ap_ctrl_none port=return


	static states_type state = zero;
	static unsigned int counter = PULSE_PERIOD-1;


	states_type  next_state;
	unsigned int next_counter;

	bool periodic_pulses_local;

	switch(state) {
	case zero:
		if (counter == 1) {
			next_counter           = counter-1;
			next_state             = one;
		} else {
			next_counter           = counter-1;
			next_state             = zero;
		}
		periodic_pulses_local = 0;
		break;
	case one:
		next_counter           = PULSE_PERIOD-1;
		next_state             = zero;
		periodic_pulses_local = 1;



		break;
	default:
		break;
	}

	state = next_state;
	counter = next_counter;
	periodic_pulses = periodic_pulses_local;
}

