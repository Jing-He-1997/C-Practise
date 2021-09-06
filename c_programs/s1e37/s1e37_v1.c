#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr;
	ptr = (int *)malloc(sizeof(int));//将void类型的指针显式的转换成int类型的指针

	if(ptr == NULL)
	{
		printf("分配内存失败！！\n");
		exit(1);
	}

	printf("请输入一个整数：");
	scanf("%d", ptr);

	printf("输入的整数为%d\n", *ptr);

	free(ptr);
	printf("输入的整数为%d\n", *ptr);

	return 0;
}
