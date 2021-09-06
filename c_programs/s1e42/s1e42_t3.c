#include <stdio.h>

int main(void)
{
	struct A
	{
		int a;
		char b;
		short c;
	} a;

	struct B
	{
		char b;
		int a;
		short c;
	} b;
	
	printf("size of a: %d\n", sizeof(a));
	printf("size of a: %d\n", sizeof(b));
	return 0;
}
