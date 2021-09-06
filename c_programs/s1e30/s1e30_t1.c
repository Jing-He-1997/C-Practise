#include <stdio.h>

int *func(int n);

int *func(int n)
{
	n++;

	return &n;//会出现警告，返回局部变量的地址！！！
}

int main(void)
{
	printf("%d\n",*func(520));
	return 0;
}
