#include <stdio.h>

int main(void)
{
	struct Test
	{
		char *p;
		long x;
		char c;
	}test = {NULL, 0, '0'};

	printf("size of test = %d\n", sizeof(test));
	return 0;
}
