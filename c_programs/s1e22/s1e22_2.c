#include <stdio.h>

#define MAX 1024
int main()
{
	char str1[MAX];
	char str2[MAX];
	char *p = str2;

	printf("请输入一个字符串到str1中：");
	fgets(str1, MAX, stdin);

	printf("开始拷贝str1的内容到str2中...\n");

	char ch;
	int i = 0;
	while(1)
	{
		ch = str1[i];
		if(ch == '\0')
		{
			break;
		}
		i++;
	}

	for(int j = 0; j < i; j++)
	{
		*(p + j) = str1[j];
	}

	printf("拷贝完毕！现在，str2中的内容是：%s",str2);

	return 0;
}
