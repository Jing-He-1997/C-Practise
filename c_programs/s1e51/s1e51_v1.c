#include <stdio.h>
#include <string.h>

union Test
{
	int i;
	double pi;
	char str[6];
};

int main(void)
{
	union Test test;
	test.i = 1;
	test.pi = 3.14;
	
	strcpy(test.str, "JINGG");

	printf("Addr of test.i is %p\n", &test.i);
	printf("Addr of test.pi is %p\n", &test.pi);
	printf("Addr of test.str is %p\n", test.str);
	return 0;
}
