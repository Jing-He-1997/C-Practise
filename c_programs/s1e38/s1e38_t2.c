#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int *ptr =NULL;

	//相当于调用malloc(size)
	ptr = realloc(NULL, 1024);
	if(ptr == NULL)
	{
		exit(1);
	}

	free(ptr);

	return 0;
}
