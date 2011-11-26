long double trapezoid(long double (*f)(long double), long double a, long double b, int n){
    const long double h = (b-a)/n;
    long double sum = 0.5L * (f(a)+f(b));

    for(int i = 1; i < n; i++)
        sum += f(a + i*h);

    return h*sum;
}

long double simpsonOneThird(long double (*f)(long double), long double a, long double b, int n){
	const long double h = (b-a)/n;
	long double part_1 = f(a)+f(b), part_2 = 0, part_3 = 0;

	for(int i = 1, max = n; i <= max; i += 2)
		part_2 += f(a + i * h);
	part_2 *= 4;

	for(int i = 2, max = n-1; i <= max; i += 2)
		part_3 += f(a + i * h);
	part_3 *= 2;

	return h/3.0L * (part_1 + part_2 + part_3);
}

long double simpsonThreeEighths(long double (*f)(long double), long double a, long double b, int n){
    const long double h = (b-a)/n;
    long double part_1 = f(a)+f(b), part_2 = 0, part_3 = 0;

    for(int i = 1, max = n - 2; i <= max; i += 3)
        part_2 += f(a+i*h);
    for(int i = 2, max = n - 1; i <= max; i += 3)
        part_2 += f(a+i*h);
    part_2 *= 3;

    for(int i = 3, max = n - 3; i <= max; i += 3)
        part_3 += f(a+i*h);
    part_3 *= 2;

    return 3.0L/8.0L * h * (part_1 + part_2 + part_3);
}

long double boole(long double (*f)(long double), long double a, long double b, int n){
    const long double h = (b-a)/n;
    long double part_1 = (f(a)+f(b)) * 7, part_2 = 0, part_3 = 0, part_4 = 0;

    for(int i = 1, max = n-1; i <= max; i+= 2)
        part_2 += f(a+i*h);
    part_2 *= 32;

    for(int i = 2, max = n-2; i <= max; i+= 4)
        part_3 += f(a+i*h);
    part_3 *= 12;

    for(int i = 4, max = n - 4; i <= max; i+=4)
        part_4 += f(a+i*h);
    part_4 *= 14;

    return 2.0L/45.0L * h * (part_1 + part_2 + part_3 + part_4);
}
