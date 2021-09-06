#include <stdio.h>

void func(void);
int main(void)
{
	extern int count;
	func();
	count++;//这里得用extern标识符先定义，编译器才能看到全局变量count
	printf("In main, count = %d\n", count);	

	return 0;
}

int count;

void func(void)
{
	count++;
	printf("In func, count = %d\n", count);
}
