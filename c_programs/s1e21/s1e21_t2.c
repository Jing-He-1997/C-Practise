#include <stdio.h>


int main()
{
	int *a, b;
	
	b = 110;
	a = &b;

	printf("%d\n",*a);

	return 0;
}
