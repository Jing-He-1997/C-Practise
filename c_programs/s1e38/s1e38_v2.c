#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
int main(void)
{
	int *ptr = NULL;

	ptr = (int *)malloc(sizeof(int) * N);

	if(ptr == NULL)
	{
		exit(1);
	}

	//First arugment is the target address of initialization
	//Second argument is the value which uses for initialization
	//Third argument is the length of the initialization
	memset(ptr, 0, sizeof(int) * N);

	int length = sizeof(int) * N / sizeof(int);
	
	for(int i = 0; i < N; i++)
	{
		printf("%d ", ptr[i]);
	}
	putchar('\n');

	free(ptr);
	return 0;
}
