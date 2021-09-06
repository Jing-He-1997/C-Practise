#include <stdio.h>

int main(void)
{
	struct Test
	{
		char c;
		char *p;
		int x;
	}test = {'0', NULL, 0};

	printf("size of test = %d\n", sizeof(test));
	return 0;
}
