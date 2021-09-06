#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t count = 0;

	while(1)
	{
		malloc(1024);
		printf("%u\n", count++);
	}

	return 0;
}
