#include <stdio.h>

int main()
{
	double i;
	int count = 0;

	for(i = 10; i > 0; i /= 2)
	{
		count++;
	}
	
	printf("循环执行了%d次\n",count);
	
	return 0;
}
