#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 

int main(void)
{
	FILE *fp;

	if((fp = fopen("yagenjiubucunzai.txt", "r")) == NULL)
	{
		//	还需要引入一个string.h的头文件 才能使用strerror(errno)
		fprintf(stderr, "ERROR: -> %s <-\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	fclose(fp);

	return 0;
}
