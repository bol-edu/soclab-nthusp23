#ifndef __FIR_H__
#define __FIR_H__

#include <ap_axi_sdata.h>
#include <hls_stream.h>

#define	N						11

#define MAP_ALIGN_4INT			(((N + 3) >> 2) << 2)

typedef ap_axiu<32,1,1,1> value_t;
typedef hls::stream<value_t> stream_t;
typedef ap_uint<32> reg32_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

void fir_n11_strm(stream_t* pstrmInput, stream_t* pstrmOutput, int32_t an32Coef[MAP_ALIGN_4INT], reg32_t regXferLeng);

#endif
