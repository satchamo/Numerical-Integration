long double trapezoid(long double (*f)(long double), long double a, long double b, int n){
	const long double h = (b-a)/n;
	long double sum = 0.5L * (f(a)+f(b));
	
	for(int i = 1; i < n; i++)
		sum += f(a + i*h);

	return h*sum;
}

long double simpsonOneThird(long double (*f)(long double), long double a, long double b, int n){
    return 0.0;
}

long double simpsonThreeEighths(long double (*f)(long double), long double a, long double b, int n){
    return 0.0;
}

long double boole(long double (*f)(long double), long double a, long double b, int n){
    return 0.0;
}
