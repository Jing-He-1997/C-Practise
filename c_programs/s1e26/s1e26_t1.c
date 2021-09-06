#include <stdio.h>

int main()
{
	int num = 520;
	int *p1 = &num;
	int *p2 = &num;
	int **pp1 = &p1;
	int ***p3 = &pp1;

	printf("p1: %p, p2: %p, pp1: %p, p3: %p\n", p1, p2, pp1, p3);

	printf("p1: %p, p1+1: %p\n", p1, p1+1);
	printf("p2: %p, p2+1: %p\n", p2, p2+1);
	printf("pp1: %p, pp1+1: %p\n", pp1, pp1+1);
	printf("p3: %p, p3+1: %p\n", p3, p3+1);

	printf("*p3: %p, **p3: %p, ***p3: %d\n", *p3, **p3, ***p3);
	printf("*pp1: %p, **pp1: %d\n", *pp1, **pp1);
	printf("*p1: %d, *p2: %d\n", *p1, *p2);
	printf("num = %d\n", num);

	return 0;
}
