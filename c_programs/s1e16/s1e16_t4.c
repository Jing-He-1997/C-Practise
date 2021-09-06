#include <stdio.h>

int main()
{
	int a,b,c;
	a = (b = 3, c = b++ + 5, ++c + ++b);

	printf("a = %d\n", a);
	return 0;
}
