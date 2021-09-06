#include <stdio.h>

int main(void)
{
	int n;
	printf("请输入一个数字:");
	scanf("%d", &n);

	printf("Before loop, n = %d\n", n);
	while(1)
	{
		if(n++ < 10)
		{
			printf("In if, n = %d\n", n);
			break;
		}
		else
		{
			printf("In else, n = %d\n", n);
			break;
		}
	}

	printf("After loop, n = %d\n", n);
	return 0;
}
