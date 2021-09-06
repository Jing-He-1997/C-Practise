#include <stdio.h>

int main(void)
{
	char a = 0, b = 0;
	int *p = (int *)&b;

	*p = 258; //二进制表示：01 00 00 00 10

	printf("addr of a: %p, addr of b: %p\n", &a, &b);
	printf("a = %d, b = %d\n", a, b);

	return 0;
}
