#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char ch;

	if((fp = fopen("hello.txt", "r")) == NULL)
	{
		fputs("打开文件失败！\n", stderr);
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		ch = fgetc(fp);
		if(feof(fp))
		{
			break;
		}
		putchar(ch);
	}

	fputc('H', fp);

	if(ferror(fp))
	{
		fputs("文件出错啦！\n", stderr);
	}

	clearerr(fp);	//将两个指示器的状态清除

	if(feof(fp) || ferror(fp))
	{
		fputs("能看得见我吗哈哈哈哈！\n", stderr);	
	}

	fclose(fp);

	return 0;
}
