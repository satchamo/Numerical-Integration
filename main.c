#include <stdio.h>
#include <math.h>
#include "integrate.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288L
#endif
#define ITERS 10

// the integral of this from 0 to 1 is pi
static long double f(long double x){
	return 4.0L/(1.0L + x * x);
}

int main(void){
	for(int i = 0, n = 12; i <= ITERS; i++, n *= 2){
        printf("Samples: %i\n", n);
		printf("%8s | %0.20Le\n", "trap", trapezoid(f, 0.0, 1.0, n));
		printf("%8s | %0.20Le\n", "simp 1/3", simpsonOneThird(f, 0.0, 1.0, n));
		printf("%8s | %0.20Le\n", "simp 3/8",simpsonThreeEighths(f, 0.0, 1.0, n));
		printf("%8s | %0.20Le\n", "bool", boole(f, 0.0, 1.0, n));
	}

	return 0;
}
