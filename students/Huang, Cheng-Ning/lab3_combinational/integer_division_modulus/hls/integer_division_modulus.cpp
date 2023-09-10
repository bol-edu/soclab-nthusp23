const int n = 100;


int divbyconstant(int a) {
#pragma HLS INLINE off

	return a / n;
}

void integer_division_modulus(int a, int &r) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=a
#pragma HLS INTERFACE ap_none port=r

	//r = a%n;

	//r = a - n*(a/n);

	r = a-n*divbyconstant(a);
}
