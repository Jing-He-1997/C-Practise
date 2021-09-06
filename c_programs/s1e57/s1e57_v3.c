#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp1;
	FILE *fp2;
	int ch;

	if((fp1 = fopen("hello.txt", "w")) == NULL)
	{
		printf("打开文件失败!\n");
		exit(EXIT_FAILURE);
	}

	if((fp2 = fopen("jing.txt", "r")) == NULL)
	{
		printf("打开文件失败!\n");
		exit(EXIT_FAILURE);
	}

	while((ch = fgetc(fp2)) != EOF)
	{
		fputc(ch, fp1);
	}

	fclose(fp1);
	fclose(fp2);

	if((fp1 = fopen("hello.txt", "r")) == NULL)
	{
		printf("打开文件失败!\n");
		exit(EXIT_FAILURE);
	}

	while((ch = fgetc(fp1)) != EOF)
	{
		putchar(ch);
	}

	fclose(fp1);
	
	return 0;
}
