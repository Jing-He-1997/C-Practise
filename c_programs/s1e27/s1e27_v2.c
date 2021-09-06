#include <stdio.h>

int main()
{
	int num = 520;
	const int cnum = 880;
	const int *p = &cnum;

	printf("cnum = %d, &cnum = %p\n", cnum, &cnum);
	printf("*p = %d, p = %p\n", *p, p);

	p = &num;
	printf("p = &num后\n");
	printf("num = %d, &num = %p\n", num, &num);
	printf("*p = %d, p = %p\n", *p, p);

	num = 1024;
	printf("num = %d, &num = %p\n", num, &num);
	printf("*p = %d, p = %p\n", *p, p);
	return 0;
}
