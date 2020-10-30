double precision_analysis(double *radioactivity, double *time, int N, double precision)
{
	int i = 0;

	double diviation1 = 0, diviation2 = 0;
	double non_lin = 0, lin = 0;
	double div = 0;

	for (i = 50; div < 2; i++)
	{
		printf("Number of points: %d, div = %lg\n", i, div);
		non_lin = nonlinear_equation(radioactivity, time, i, precision);
		lin = linear_equation(radioactivity, time, i);
		diviation1 = dev_exp(radioactivity, time, i, non_lin);
		diviation2 = dev_linear(radioactivity, time, i, lin);
		div = diviation2/diviation1;
		printf("Non lin = %lg, lin = %lg, Div1= %lg, div2 = %lg\n", non_lin, lin, diviation1, diviation2);
	}

	return time[i];
}
