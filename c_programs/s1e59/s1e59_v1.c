#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;

	if((fp = fopen("s1e59_v1.txt", "w")) == NULL)
	{
		printf("打开文件失败!\n");
		exit(EXIT_FAILURE);
	}

	printf("%ld\n", ftell(fp));
	fputc('H',fp);
	printf("%ld\n", ftell(fp));
	fputs("e Jing\n",fp);
	printf("%ld\n", ftell(fp));
	
	rewind(fp);
	fputs("XIXI", fp);

	fclose(fp);
	return 0;
}

