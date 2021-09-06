#include <stdio.h>

int main()
{
	int num = 520;
	int *p = &num;
	int **pp = &p;

	printf("*pp = %p, p = %p, &num = %p\n", *pp, p, &num);

	printf("**pp = %d\n",**pp);
	printf("*p = %d\n",*p);

	printf("pp = %p, &p = %p\n", pp, &p);// pp的值是p的地址
	
	return 0;
}
