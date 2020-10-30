#define A radioactivity, time, N, a
#define DECAY_TIME radioactivity, time, N, decay_time
#include <math.h>

double nonlinear_equation(double *radioactivity, double *time, int N, double precision);

double model(double *radioactivity, double *time, int N, double point);

double linear_equation(double *radioactivity, double *time, int N);
 
double model(double *radioactivity, double *time, int N, double point)
{

	double sum = 0;
	int i = 0;

	for(i = 0; i < N; i++)
	{
		sum += ( time[i]*expl(-time[i]/point) * (radioactivity[i] - expl(-time[i]/point)) );
	}
	return sum;
	}

double nonlinear_equation(double *radioactivity, double *time, int N, double precision)
{

	double a = 0.2,
	b = 8.2;

	double decay_time = 0;


	do
	{

		decay_time = (a+b) / 2;

		if (model(A) * model(DECAY_TIME) < 0)
			b = decay_time;

		else if (model(A) * model(DECAY_TIME) > 0)
			a = decay_time;

		else
			return decay_time;

	} while(fabs(model(DECAY_TIME)) > precision);


	return decay_time;
}

double linear_equation(double *radioactivity, double *time, int N)
{

	double sum1 = 0,
	sum2 = 0;

	int i = 0;

	for(i = 0; i < N; i++)
	{
		sum1 += pow(time[i], 2);
		sum2 += time[i] * (1 - radioactivity[i]);
	}

	double decay_rate = sum1 / sum2;
	return decay_rate;
}
