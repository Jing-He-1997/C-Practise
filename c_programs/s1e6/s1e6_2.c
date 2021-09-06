#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long result = 0;
	unsigned long long kg;
	unsigned long long temp;

	int i;
	for(i = 0; i < 64; i++)
	{
		temp = pow(2,i);
		result = result + temp;
	}
	
	kg = result / 25000;

	printf("舍罕王应该给予达依尔%llu粒麦子\n应该给%llukg麦子\n",result, kg);
	return 0;	
}
