#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;

	if((fp = fopen("s1e61_v1.txt", "w")) == NULL)
	{
		perror("打开文件失败，原因是");
		exit(EXIT_FAILURE);
	}

	fputs("My name is Jing He and My ins name is Pauljingger", fp);

	getchar();	// 阻塞函数，如果不执行这个函数，那么程序会一直卡在这里

	fclose(fp);
	
	return 0;
}
