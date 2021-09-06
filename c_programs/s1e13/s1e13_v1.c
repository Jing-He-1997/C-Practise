#include <stdio.h>

int main()
{
	int sum = 0, i = 1;
	while(i <= 100)
	{
		sum = sum + i;
		i++;
	}

	printf("最后得到的值为：%d\n",sum);
	return 0;
}
