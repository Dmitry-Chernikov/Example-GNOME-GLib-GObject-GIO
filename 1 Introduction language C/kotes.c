#include "kotes.h"

double Kotes(int_fun f, double a, double b, int n){

	int N = 2*n;
	double h = (b-a)/N;
	double x, sum1, sum2;

	for (int i = 1; i < N; i++){

		x = a + i*h;

		if (i % 2 == 0) {

			sum2 = sum2 + f(x);

		} else {

			sum1 = sum1 + f(x);

		}
	}

	return h*(f(a) + 2*sum2 + 4*sum1 + f(b)) / 3;
}
