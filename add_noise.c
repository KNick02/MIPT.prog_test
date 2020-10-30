#include <time.h>

void add_noise (double *radioactivity, int N)
    {
	srand (time(NULL));
    int i;
    for (i = 0; i < N; i++)
        {
        double randomDeflection = 1.0 * 0.05 * (100000 - rand()%200000) / 100000;

        radioactivity[i] = radioactivity[i] + randomDeflection;
        }
    }
