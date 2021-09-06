#include <stdio.h>

void a();
void b();
void c();

void a()
{
	printf("A\n");
}
int main()
{
	b();
	a();
	c();
	return 0;
}

void c()
{
	printf("C\n");
}
void b()
{
	printf("B\n");
}
