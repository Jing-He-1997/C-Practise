#include <stdio.h>

long fact(int num);

long fact(int num)
{
	long result;
	if(num > 0)
	{
		result = num * fact(num - 1);
	}
	else
	{
		result = 1;
	}
	return result;
}
int main(void)
{
	int num;
	printf("请输入一个数字：");
	scanf("%d", &num);

	printf("%d的阶乘为：%d\n", num, fact(num));

	return 0;
}
