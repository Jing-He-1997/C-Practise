#include <stdio.h>

int main(void)
{
	int value = 1;
	
	while(value < 1024)
	{
		value <<= 1;
		printf("value = %d\n", value);
	}

	printf("\n**************分隔线****************\n\n");

	value = 1024;
	while(value > 0)
	{
		value >>= 2;
		printf("value = %d\n", value);
	}

	return 0;
}
