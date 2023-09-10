#include "binary2bcd_double_dabble.h"



void double_dabble(uint16 &scratch_pad) {
#pragma HLS INLINE

	scratch_pad = scratch_pad << 1;
	if (scratch_pad(11, 8) > 4)
		scratch_pad(11, 8) = scratch_pad(11, 8) + 3;

}



void binary2bcd_double_dabble(uint8 in_binary, uint16 *unpacked_bcd, uint8 *packed_bcd) {
#pragma HLS INTERFACE ap_none port=in_binary
#pragma HLS INTERFACE ap_none port=unpacked_bcd
#pragma HLS INTERFACE ap_none port=packed_bcd
#pragma HLS INTERFACE ap_ctrl_none port=return

	uint16 scratch_pad = in_binary;
	uint4  zero_4      = 0b0000;


	double_dabble(scratch_pad);
	double_dabble(scratch_pad);
	double_dabble(scratch_pad);
	double_dabble(scratch_pad);

	double_dabble(scratch_pad);
	double_dabble(scratch_pad);
	double_dabble(scratch_pad);
	scratch_pad = scratch_pad << 1;


	*packed_bcd   = scratch_pad(15, 8);
	*unpacked_bcd = (zero_4, scratch_pad(15, 12), zero_4, scratch_pad(11, 8));

}
