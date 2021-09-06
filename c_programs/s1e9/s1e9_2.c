#include <stdio.h>
#include <math.h>

int main()
{
	float res1,res2,res3;

	res1 = 10000 * (1 + 0.0275 * 5);
	res2 = (10000 * (1 + 0.0275 * 3)) * (1 + 0.0225 * 2);
	res3 = 10000 * pow ((1 + 0.0175), 5);

	printf("%.2f\n%.2f\n%.2f\n",res1,res2,res3);

	return 0;
}
