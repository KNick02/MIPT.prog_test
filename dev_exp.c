#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dev_exp(double *radioactivity, double *time, int M, double decay_time)
{
        double sum_residuals1 = 0;
        int i = 0;
        for (i = 0; i < M; i++)
            sum_residuals1 += pow(radioactivity[i] - expl(-time[i]/decay_time), 2);
	
	double res = sqrt(sum_residuals1)/M;

	return res;
}
