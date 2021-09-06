#include <stdio.h>

#define MAX 1024

int main()
{
	char str1[MAX];
	char str2[MAX];

	char *target1 = str1;
	char *target2 = str2;

	char ch;
	int n;

	printf("请输入一个字符串到str1中：");
	fgets(str1, MAX, stdin);

	printf("开始拷贝str1的内容到str2中...\n");
	while((*target2++ = *target1++)!='\0')//将str1复制到str2中
	{
		;
	}

	printf("拷贝完毕！");
	printf("现在，str2中的内容是:%s",str2);//这里不用加\n，因为str1中本来就有换行符

	return 0;
}
