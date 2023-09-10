#include <iostream>
#include "FIR.h"

using namespace std;

#define NUM_SAMPLES			600

int main(int argc, char *argv[])
{
	FILE         *fp;

	int32_t signal;
	int32_t input[NUM_SAMPLES], output[NUM_SAMPLES];
	int32_t taps[N] = {0,-10,-9,23,56,63,56,23,-9,-10,0};

	int i, ramp_up;

	cout << ">> Start test!" << endl;

	signal = 0;
	ramp_up = 1;

	fp = fopen("out.dat", "w");
	for (i = 0; i < NUM_SAMPLES; i++) {
		if (ramp_up == 1)
			signal = signal + 1;
		else
			signal = signal - 1;

		input[i] = signal;

		if ((ramp_up == 1) && (signal >= 75))
			ramp_up = 0;
		else if ((ramp_up == 0) && (signal <= -75))
			ramp_up = 1;
	}

	// Execute the function with latest input
	fir_n11_maxi(input, output, taps, NUM_SAMPLES * sizeof(int32_t));

	// Save the results.
	for (i = 0; i < NUM_SAMPLES; i++) {
		fprintf(fp,"%i %d %d\n", i, input[i], output[i]);
	}

	fclose(fp);

	cout << ">> Comparing against output data..." << endl;
	if (system("diff ./out.dat /home/ubuntu/course-lab_2/AXI_Master/hls_FIRN11MAXI/out_gold.dat")) {
		cout << ">> Test failed!" << endl;
		return 1;
	}

	cout << ">> Test passed!" << endl;
	cout << "------------------------" << endl;
	return 0;
}
