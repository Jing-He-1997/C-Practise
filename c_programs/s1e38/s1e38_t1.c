#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int *ptr = NULL;

	//先在堆中申请一个空间大小为sizeof(int) * 1024的动态内存空间
	ptr = (int *)malloc(sizeof(int) * 1024);
	if(ptr == NULL)
	{
		printf("动态内存申请失败！！\n");
		exit(1);
	}

	//初始化内存空间
	memset(ptr, 0, sizeof(int)* 1024);

	free(ptr);

	return 0;
}
