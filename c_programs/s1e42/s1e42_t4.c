#include <stdio.h>

int main(void)
{
	struct A
	{
		int x;
		int y;
	};

	struct A a;
	a.x = 3;
	a.y = 4;

	printf("%d,%d\n",a.x, a.y);
	return 0;
}
