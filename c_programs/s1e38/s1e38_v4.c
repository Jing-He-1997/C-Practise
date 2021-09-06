#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr = NULL;
	int n = 1, i;
	while(1)
	{
		ptr = (int *)realloc(ptr, sizeof(int) * n);
		printf("请输入一个数字：");
		scanf("%d",&ptr[n - 1]);
		
		if(ptr[n - 1] == -1)
		{
			printf("退出！！！\n");
			break;
		}
		n++;
	}

	printf("用户输入的有效数字为：");
	for(i = 0; i < n - 1; i++)
	{
		printf("%d ", ptr[i]);
	}
	putchar('\n');

	free(ptr);
	return 0;
}
