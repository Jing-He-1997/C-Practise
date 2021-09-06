#include <stdio.h>


void func();

void func()
{
	extern count;// c99要加类型声明，不是c99就没事
	count ++;
}

int count = 0;

int main()
{
	func();
	printf("count = %d\n", count);

	return 0;
}
