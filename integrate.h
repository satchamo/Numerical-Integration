#ifndef INTEGRATE_H
#define INTEGRATE_H

// a is the left bound, b is the right bound, n is the number of samples
long double trapezoid(long double (*f)(long double), long double a, long double b, int n);
long double simpsonOneThird(long double (*f)(long double), long double a, long double b, int n);
long double simpsonThreeEighths(long double (*f)(long double), long double a, long double b, int n);
long double boole(long double (*f)(long double), long double a, long double b, int n);

#endif
