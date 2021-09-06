#include <stdio.h>

int main()
{
	int i, j;
	int num, count = 0;
	printf("请输入一个数字（不大于10000）：");
	scanf("%d",&num);

	for(i = 2; i <= num; i++)
	{
		for(j = 2; j < i; j++)
		{
			if(i % j == 0)
			{
				count++;
				break;
			}
		}
	}
	printf("%d内共有%d个素数\n", num, num - count - 1);
	return 0;
}
