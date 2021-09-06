#include <stdio.h>

int main()
{
	int a = 1, b = 2, c = 3;
	long long sum = 2;

	for(int i = 2; c < 4000000; i++)
	{
		c = a + b;
		a = b;
		b = c;

		if(c % 2 == 0)
		{
			sum += c;
		}
	}

	printf("结果为：%d\n",sum);
	return 0;
}
