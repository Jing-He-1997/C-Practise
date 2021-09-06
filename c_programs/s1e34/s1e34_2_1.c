#include <stdio.h>
// 用迭代计算fibonacci数列效率可以提高非常多！
unsigned int fibonacci (unsigned int n);

unsigned int fibonacci(unsigned int n)
{
	if(n == 1||n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}
int main()
{
	unsigned int number, i;

	printf("请输入一个整数：");
	scanf("%u", &number);

	printf("Fibonacci数列的前%d个数字是：", number);

	for(i = 1; i <= number; i++)
	{
		printf("%lu ", fibonacci(i));
	}

	putchar('\n');

	return 0;
}
