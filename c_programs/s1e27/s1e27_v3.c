#include <stdio.h>

int main()
{
	int num = 520;
	const int cnum = 880;
	int * const p = &num; //常量指针

	const int * const p1 = &cnum; //指向常量的常量指针，p1和*p1都无法被修改

	printf("*p = %d, p = %p\n",*p, p);
	*p = 1024;
	printf("*p = %d, p = %p\n",*p, p);
	return 0;
}
