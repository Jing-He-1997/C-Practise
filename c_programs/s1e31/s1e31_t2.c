#include <stdio.h>
int i = 520;

void func(void);

void func(void)
{
	printf("%d, ", i);

	int i = 880;

	for(int i = 1; i < 3; i++)
	{
		printf("%d, ", i);
	}

	printf("%d\n", i);
}
int main()
{
	func();
	
	return 0;
}
