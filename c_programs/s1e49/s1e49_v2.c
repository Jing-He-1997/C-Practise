#include <stdio.h>

#define integer int

int main(void)
{
	integer a;
	int b;
	a = 520;
	b = a;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("size of a = %d\n", sizeof(a));
	printf("size of b = %d\n", sizeof(b));

	return 0;
}




