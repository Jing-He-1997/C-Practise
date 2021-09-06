#include <stdio.h>

int main()
{
	int num1 = 220;
	int num = 520;
	const int * const a = &num1;
	const int cnum = 880;
	const int * const p = &num;

	const int * const *pp = &p; // pp指针可以改变指向的地址

	printf("pp = %p, &p = %p\n", pp, &p);
	printf("*pp = %p, p = %p, &num = %p\n", *pp, p, &num);
	printf("**pp = %d, *p = %d, num = %d\n", **pp, *p, num);

	pp = &a;
	printf("pp = %p, &p = %p\n", pp, &p);
	printf("*pp = %p, p = %p\n", *pp, &p);
	printf("**pp = %d, *p = %d\n", **pp, *p);
	

	return 0;
}
