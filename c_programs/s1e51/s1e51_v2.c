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

	printf("test.i = %d\n", test.i);
	printf("test.pi = %.2f\n", test.pi);
	printf("test.str = %s\n", test.str);
	return 0;
}
