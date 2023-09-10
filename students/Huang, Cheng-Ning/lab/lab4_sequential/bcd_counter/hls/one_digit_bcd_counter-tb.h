#pragma once

#include "one_digit_bcd_counter.h"


void bcd_counter(bool pulse, ap_uint<8> &seven_segment_data, ap_uint<4> &seven_segment_enable);
