#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dev_linear(double *radioactivity, double *time, int M, double decay_rate){
        double sum_residuals2 = 0;
        int i;
        for (i = 0; i < M; i++){
            sum_residuals2 += pow(radioactivity[i] - (1 - time[i]/decay_rate), 2);
        }
        return sqrt(sum_residuals2)/M;
}
