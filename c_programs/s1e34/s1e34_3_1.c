#include <stdio.h>


//递归函数中输出在递归函数后，一般情况下是reverse
void binary(unsigned long n);

void binary(unsigned long n)
{
	int r; //Tips：递归在设置一个值时可以不初始化

	r = n%2;

	if(n>=2)
	{
		binary(n/2);
	}

	putchar('0'+ r); //'0'+1='1'
}
int main(void)
{
	unsigned long number;

	printf("请输入一个正整数：");
	scanf("%lu", &number);

	binary(number);
	putchar('\n');

	return 0;
}
