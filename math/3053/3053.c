#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES
int main()
{
	double num;
	double temp;
	scanf("%lf", &num);
	temp = num;

	temp = pow(temp, 2.0) * M_PI;
	num = num * sqrt(2.0);
	num = pow(num, 2.0);
	printf("%f\n", temp);
	printf("%f", num);
}
