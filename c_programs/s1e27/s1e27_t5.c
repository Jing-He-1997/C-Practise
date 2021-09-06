#include <stdio.h>

int main(void)
{
	const int num = 520;
	const int * const p = &num;

	//限制了*q 和 **q	
	const int * const *q = &p;
	printf("%d\n", **q);

	const int num1 = 1024;
	const int *const p1 = &num1;
	
	q = &p1;
	printf("%d\n", **q);

	return 0;
}
