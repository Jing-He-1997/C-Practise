#include <stdio.h>

int main()
{
	int a = 110;
	int *b = &a;

	*b = *b -10;// b指向的是a的地址

	printf("a = %d\n",a);
	printf("the addr of a = %p\n",a);
	printf("the addr of *b = %p\n",*b);
	printf("the addr of b = %p\n",b);

	return 0;
}
