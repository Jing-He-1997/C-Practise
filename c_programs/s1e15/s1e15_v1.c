#include <stdio.h>

int main()
{
	long long num;
	_Bool flag = 1;//通过布尔值来实现不同条件的输出

	printf("请输入一个整数：");
	scanf("%lld",&num);

	for(int i = 2; i< num; i++)
	{
		if(num % i == 0)
		{
			flag =  0;
			break;
		}
	}
	
	if(flag)
	{
		printf("%lld是素数！\n",num);
	}
	else
	{
		printf("%lld是质数！\n",num);
	}

	return 0;
}
