#include <stdio.h>

int main(void)
{
	struct Test
	{
		unsigned int a:33;
		unsigned int b:1;
		unsigned int c:2;
	};

	struct Test test;
	test.a = 0;
	test.b = 1;
	test.c = 2;
	printf("size of test = %d\n", sizeof(test));
	printf("a = %d, b = %d, c = %d\n", test.a, test.b, test.c);

	return 0;
}
