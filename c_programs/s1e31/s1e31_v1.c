#include <stdio.h>

int main()
{
	int i = 520;
	printf("before loop, i = %d\n", i );
	
	for(int i = 0; i < 3; i++)
		printf("i = %d\n", i);

	printf("after loop, i = %d\n", i );
	return 0;
}
