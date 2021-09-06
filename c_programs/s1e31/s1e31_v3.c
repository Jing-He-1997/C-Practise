#include <stdio.h>

int a, b = 520;
void func();

void func()
{
	a = 880;
	int b = 120;

	printf("In func, a = %d, b = %d\n", a, b);
}
int main()
{
	printf("In main, a = %d, b = %d\n", a, b);
	func();	
	printf("After implementing func, a = %d, b = %d\n", a, b);
	return 0;
}
