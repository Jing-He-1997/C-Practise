#include <stdio.h>

int main()
{
	int num;
	int count = 2;
	_Bool flag = 1;
	printf("请输入一个数字（不大于10000）：");
	scanf("%d",&num);

	for(int i = 5; i <= num; i++)
	{
		for(int j = 2; j <= i / 2; j++)
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

	printf("%d内共有%d个素数\n",num, count);
	return 0;
}
