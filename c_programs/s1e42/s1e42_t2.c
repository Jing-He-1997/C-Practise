#include <stdio.h>

int main(void)
{
	struct A
	{
		int a;
		char b;
		short c;
	} a;

	printf("size of a: %d\n", sizeof(a));
	return 0;
}
