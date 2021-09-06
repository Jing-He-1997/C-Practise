#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	int ch;

	if((fp = fopen("hello.txt", "r")) == NULL)
	{
		printf("打开文件失败!\n");
		exit(EXIT_FAILURE);
	}

	while((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}

	fclose(fp);	// 当对一个文件完成读写操作的时，必须用fclose函数关闭;
			// fclose的参数就是fopen返回的这个文件指针;
			// 只有调用了fclose函数，系统才会将缓冲区内的数据写入文件中;
			// 成功关闭文件后，文件指针就失效了。

	return 0;
}
