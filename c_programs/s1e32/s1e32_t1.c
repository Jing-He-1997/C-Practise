#include <stdio.h>

void func();

void func()
{
A:
	printf("NO\n");
B:
	printf("YES\n");
}

int main()
{
//	goto A; //函数作用域只作用在同一个函数里
	func();
//	goto B;

	return 0;
}
