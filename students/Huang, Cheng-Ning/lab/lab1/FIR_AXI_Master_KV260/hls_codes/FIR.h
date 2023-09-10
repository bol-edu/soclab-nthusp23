#ifndef __FIR_H__
#define __FIR_H__

#include <ap_axi_sdata.h>

#define	N						11

#define MAP_ALIGN_4INT			(((N + 3) >> 2) << 2)

typedef ap_uint<32> reg32_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

void fir_n11_maxi(volatile int32_t* pn32HPInput, volatile int32_t* pn32HPOutput, int32_t an32Coef[MAP_ALIGN_4INT], reg32_t regXferLeng);

#endif
