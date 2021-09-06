#include <stdio.h>

#define MAX 1024

int main()
{
	char str[MAX];
	char *target = str;

	printf("请输入一个字符串：");
	fgets(str, MAX, stdin);

	int length = 0;

	while(*target++ != '\0')
	{
		length++;
	}

	printf("该字符串的长度为：%d\n",length - 1);

	return 0;
}
