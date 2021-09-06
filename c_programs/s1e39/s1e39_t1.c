#include <stdio.h>

void func1(void);
void func2(void);

void func1(void)
{
	int a = 520;
	printf("value of a is %d\n", a);
	printf("addr of a is %p\n", &a);
}

void func2(void)
{
	int b = 880;
	printf("value of b is %d\n", b);
	printf("addr of b is %p\n", &b);
}

int main(void)
{	
	func1();
	func2();

	return 0;
}
