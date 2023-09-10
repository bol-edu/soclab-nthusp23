#include <iostream>
#include "FIR.h"

using namespace std;

#define NUM_SAMPLES			600

int main(int argc, char *argv[])
{
	FILE         *fp;

	int32_t signal;
	int32_t input[NUM_SAMPLES], output[NUM_SAMPLES];
	stream_t strmInput, strmOutput;
	int32_t taps[N] = {0,-10,-9,23,56,63,56,23,-9,-10,0};
	value_t valDataCtrl;

	int i, ramp_up;

	cout << ">> Start test!" << endl;

	signal = 0;
	ramp_up = 1;
	valDataCtrl.data = 0;
	valDataCtrl.keep = 0xF;
	valDataCtrl.strb = 0;
	valDataCtrl.user = 0;
	valDataCtrl.last = 0;
	valDataCtrl.id = 0;
	valDataCtrl.dest = 0;

	fp = fopen("out.dat", "w");
	for (i = 0; i < NUM_SAMPLES; i++) {
		if (ramp_up == 1)
			signal = signal + 1;
		else
			signal = signal - 1;

		input[i] = signal;
		valDataCtrl.data = signal;
		if (i >= (NUM_SAMPLES - 1)) valDataCtrl.last = 1;
		strmInput.write(valDataCtrl);

		if ((ramp_up == 1) && (signal >= 75))
			ramp_up = 0;
		else if ((ramp_up == 0) && (signal <= -75))
			ramp_up = 1;
	}

	// Execute the function with latest input
	fir_n11_strm(&strmInput, &strmOutput, taps, NUM_SAMPLES * sizeof(int32_t));

	// Save the results.
	for (i = 0; i < NUM_SAMPLES; i++) {
		output[i] = strmOutput.read().data;
		fprintf(fp,"%i %d %d\n", i, input[i], output[i]);
	}

	fclose(fp);

	cout << ">> Comparing against output data..." << endl;
	if (system("diff ./out.dat /home/ubuntu/course-lab_2/Stream/hls_FIRN11Stream/out_gold.dat")) {
		cout << ">> Test failed!" << endl;
		return 1;
	}

	cout << ">> Test passed!" << endl;
	cout << "------------------------" << endl;
	return 0;
}
