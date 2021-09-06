#include <stdio.h>

#define MAX 1024

int main()
{
	char str1[MAX];
	char str2[MAX];
	int length;
	char ch;

	char *target1 = str1;
	char *target2 = str2;

	printf("请输入一个字符串到str1中：");
	fgets(str1, MAX, stdin);

	printf("请输入需要拷贝的字符个数：");
	scanf("%d",&length);

	
	//判断条件：先将length_max减1再进行复制
	while(length--)
	{	 ch = *target2++ = *target1++;
		if(ch == '\0')
		{
			break;	
		}
		if((int)ch < 0)
		{
			*target2++ = *target1++;
			*target2++ = *target1++;
		}
		
	}

	*target2 ='\0';

	printf("拷贝完毕！\n");
	printf("现在，str2中的内容是：%s\n",str2);

	return 0;	
}
