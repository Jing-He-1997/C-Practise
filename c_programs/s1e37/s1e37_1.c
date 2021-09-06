#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int num, i;
	printf("请输入待录入整数的个数：");
	scanf("%d",&num);
	
	int *ptr = NULL;
	ptr = (int *)malloc(sizeof(int) * num);
	if(ptr == NULL)
	{
		printf("动态内存申请失败！\n");
	}

	for(i = 0; i < num; i++)
	{
		printf("请录入第%d个整数：", i+1);
		scanf("%d", &ptr[i]);
		getchar();
	}

	printf("你录的整数是：");
	for(i = 0; i < num; i++)
	{
		printf("%d ", ptr[i]);
	}
	putchar('\n');

	free(ptr);

	return 0;
	
}
