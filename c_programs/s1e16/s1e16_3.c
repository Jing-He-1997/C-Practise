#include <stdio.h>
#include <math.h>

int main()
{
	double i = 1, j = 1;
	double res_PI = 0;
	
	while(1)
	{	if(1 / i <  pow(10, -8))
		{
			printf("%.7lf\n",4 * res_PI);
			break;
		}

		res_PI = res_PI + (1 / i) * pow(-1, j-1);
		i += 2;
		j++;
	}

	return 0;
}
