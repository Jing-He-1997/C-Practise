#include <stdio.h>

typedef int *(*PTR_TO_FUN)(int);

int *fun1(int a)

{
	printf("num in fun1 = %d\n", a);
	return &a; // 正常情况下不要返回形参的地址，这是实验性的代码
}

int *fun2(int b)
{
	printf("num in fun2 = %d\n", b);
	return &b;
}

int *fun3(int c)
{
	printf("num in fun3 = %d\n", c);
	return &c;
}

int main(void)
{
	PTR_TO_FUN array[3] = {&fun1, &fun2, &fun3}; // 事实上不加&也可以，加上&更加正规

	int i;
	for(i = 0; i < 3; i++)
	{
		printf("the address of num in fun%d is %p\n", i+1, (*array[i])(i));
	}
	
	return 0;
}
