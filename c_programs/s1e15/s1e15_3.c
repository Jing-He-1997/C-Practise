#include <stdio.h>
#include <math.h>

int main()
{
	int num, k, i, j;
	int count = 4;
	_Bool flag = 1;
	printf("请输入一个数字（不大于10000）：");
	scanf("%d",&num);

	for(i = 9; i <= num; i++)
	{
		k = (int)sqrt((double)i);
		for(j = 2; j <= k; j++)
		{
			if(i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			count++;
		}
		else
		{
			flag = 1;
		}
	}

	printf("%d内共有%d个素数\n", num, count);
	return 0;
}
