#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num, i;
	printf("请输入要录入的整数数量：");
	scanf("%d", &num);

	int *ptr = NULL;
	ptr = (int *)malloc(sizeof(int) * num);

	for(i = 0; i < num; i++)
	{
		printf("请输入第%d个数：", i+1);
		scanf("%d", &ptr[i]);
	}

	printf("录入的整数为：");
	for(i = 0; i < num; i++)
	{
		printf("%d ", ptr[i]);
	}
	putchar('\n');

	free(ptr);
	return 0;
}
