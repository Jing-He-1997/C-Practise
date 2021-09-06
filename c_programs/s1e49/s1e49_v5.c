#include <stdio.h>

typedef int INGETER, *PTRINT;

int main(void)
{
	INGETER a;
	PTRINT b, c;

	a = 520;
	b = &a;
	c = b;

	printf("addr of &a = %p, addr of b = %p, addr of c = %p\n", &a, b ,c);
	printf("a = %d, *b = %d, *c = %d\n", a, *b, *c);

	return 0;
}
