#include <stdio.h>
//当a和b为两个函数各自的局部变量的时候，他们的地址就肯呢个会出现上述情况


void add(int);

void func1()
{
	int b = 880;
	printf("b is %d, add of b is %p\n", b, &b);
}

void func2()
{
	int a = 520;
	printf("a is %d, add of a is %p\n", a, &a);
}

int main()
{
	func1();
	func2();

	return 0;
}
