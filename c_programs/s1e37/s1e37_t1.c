#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr = NULL;

	ptr = (int *)malloc(sizeof(int));
	if(ptr == NULL)
	{
		printf("内存分配失败！\n");
		exit(1);
	}

	printf("Before free ptr = %p\n", ptr);
	free(ptr);
	printf("After free ptr = %p\n", ptr);

	return 0;
}
