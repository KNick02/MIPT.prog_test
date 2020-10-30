#include "head.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double radioactivity[100] = {0};
	double time[100] = {0};
	double start_time = 0;
	double end_time = 0;
	double step = 0;
	double precision = 0;
	double betta = 0;

	scanf("%lg %lg %lg %lg %lg", &start_time, &end_time, &step, &precision, &betta);
	
	int N = experiment (radioactivity, time, start_time, end_time, step, betta);
	printf("experiment ok\n");	
	add_noise(radioactivity, N);

	printf("add_noise ok\n");	
	double decay_time = nonlinear_equation(radioactivity, time, N, precision);

	printf("nonlinear ok\n");	
	double decay_rate = linear_equation(radioactivity, time, N);

	printf("linear ok\n");	
	double time_differences = precision_analysis(radioactivity, time, N, precision);

	printf("pr_analysis ok\n");	
	printf("decay_time: %lg\ndecay_rate: %lg\n time differences: %lg\n\n", decay_time, decay_rate, time_differences);
	return 0;
}



