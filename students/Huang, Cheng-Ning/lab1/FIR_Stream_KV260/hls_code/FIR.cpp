
#include "FIR.h"

void fir_n11_strm(stream_t* pstrmInput, stream_t* pstrmOutput, int32_t an32Coef[MAP_ALIGN_4INT], reg32_t regXferLeng)
{
#pragma HLS INTERFACE s_axilite port=regXferLeng
#pragma HLS INTERFACE s_axilite port=an32Coef
#pragma HLS INTERFACE axis register both port=pstrmOutput
#pragma HLS INTERFACE axis register both port=pstrmInput
#pragma HLS INTERFACE s_axilite port=return
	static int32_t an32ShiftReg[N];
	int32_t n32Acc;
	int32_t n32Data;
	int32_t n32Temp;
	int32_t n32Loop;
	int32_t n32NumXfer4B;
	int32_t n32XferCnt;
	value_t valTemp;

    n32NumXfer4B = (regXferLeng + (sizeof(int32_t) - 1)) / sizeof(int32_t);
XFER_LOOP:
	for (n32XferCnt = 0; n32XferCnt < n32NumXfer4B; n32XferCnt++) {
		n32Acc = 0;
		value_t valTemp = pstrmInput->read();
		n32Temp = valTemp.data;
SHIFT_ACC_LOOP:
		for (n32Loop = N - 1; n32Loop >= 0; n32Loop--) {
			if (n32Loop == 0) {
				an32ShiftReg[0] = n32Temp;
				n32Data = n32Temp;
			} else {
				an32ShiftReg[n32Loop] = an32ShiftReg[n32Loop - 1];
				n32Data = an32ShiftReg[n32Loop];
			}
			n32Acc += n32Data * an32Coef[n32Loop];
		}
		valTemp.data = n32Acc;
		pstrmOutput->write(valTemp);
		if (valTemp.last) break;
	}

	return;
}
