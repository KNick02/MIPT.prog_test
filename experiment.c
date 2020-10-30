#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int experiment (double *radioactivity, double *time, double start_time, double end_time, double step, double betta){
	double t = start_time;
    int i = 0;
    while (t <= end_time)
    {
        radioactivity[i] = expl(-t/betta);
        time[i] = t;
        i++;
        t += step;
    }
    return i;
}
