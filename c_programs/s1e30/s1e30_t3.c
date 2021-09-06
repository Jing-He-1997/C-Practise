#include <stdio.h>

#define MAX 1024
void *func(int n, int *ptr, char *str);

void *func(int n, int *ptr, char *str)
{
	if(n > 0)
	{
		return ptr;
	}
	else
	{
		return str;
	}
}

int main(void)
{

	int num;
	char str[MAX];

	printf("请输入一个数字:");
	scanf("%d", &num);

	printf("请输入测试字符串:");
	scanf("%s", str);

	printf("%d\n", *(int *)(func(1, &num, str)));
	printf("%s\n", (char *)func(-1, &num, str));
	return 0;
}
