#include <stdio.h>

void func(void);

void func(void)
{
	static int count = 0;
	count++;
	printf("%d ", count);
}
int main(void)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		func();
	}

	putchar('\n');

	return 0;
}
