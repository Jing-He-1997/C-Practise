#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;

	if((fp = fopen("text.txt", "wb")) == NULL)	//二进制写入
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}

	fputc('5', fp);
	fputc('2', fp);
	fputc('0', fp);
	fputc('\n', fp);

	fclose(fp);
	return 0;
}
