double precision_analysis(double *radioactivity, double *time, int N, double precision)
{
	int i = 0;

	double deviation1 = 0, deviation2 = 0;
	double non_lin = 0, lin = 0;
	double div = 1;
	
	for (i = 10; div < 2; i++)
	{
		non_lin = nonlinear_equation(radioactivity, time, i, precision);
		lin = linear_equation(radioactivity, time, i);
		deviation1 = dev_exp(radioactivity, time, i, non_lin);
		deviation2 = dev_linear(radioactivity, time, i, lin);
		div = deviation2/deviation1;
	}

	return time[i];
}
