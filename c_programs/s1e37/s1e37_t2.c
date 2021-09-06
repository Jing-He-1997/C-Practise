#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char (*str)[1024];//数组指针

	str = (char (*)[1024])malloc(1024);
	if(str != NULL)
	{
		printf("\n动态内存分配成功！！\n\n");
	}

	free(str);
	return 0;
}
