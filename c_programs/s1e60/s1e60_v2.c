#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	
	if((fp = fopen("yagenjiubucunzai.txt", "r")) == NULL)
	{
		printf("标准输出!\n");
		fputs("打开文件失败了!\n", stderr);
		exit(EXIT_FAILURE);
	}

	//do something...
	

	fclose(fp);

	return 0;
}
