#include <stdio.h>

void a();
void b();
void c();

int count = 0;// 不初始化，编译器会自动count = 0

void a()
{
	count++;
}

void b()
{
	count++;
}

void c()
{
	count++;
}

int main()
{
	a();
	b();
	c();
	b();

	printf("count = %d\n", count);

	return 0;
}
