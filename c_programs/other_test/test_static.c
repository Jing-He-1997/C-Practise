#include <stdio.h>

void fun(void);
void fun_static(void);

void fun(void)
{
	int n = 10;
	printf("n = %d\n", n);

	n++;
	printf("n++ = %d\n", n);
}

void fun_static(void)
{
	static int n = 10;//static 修饰的变量只执行初始化一次！！
	printf("static n = %d\n", n);

	n++;
	printf("static n++ = %d\n", n);
}

int main(void)
{
	fun();
	printf("--------------\n");
	fun_static();
	printf("--------------\n");
	fun();
	printf("--------------\n");
	fun_static();
	
	return 0;
}
