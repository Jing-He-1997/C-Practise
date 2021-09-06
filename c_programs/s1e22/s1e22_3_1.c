#include <stdio.h>

#define MAX 1024

int main()
{
	char str1[2*MAX];
	char str2[MAX];

	char *target1 = str1;
	char *target2 = str2;

	char ch;
	int length;

	printf("请输入第一个字符串：");
	fgets(str1, MAX, stdin);

	printf("请输入第二个字符串：");
	fgets(str2, MAX, stdin);

	printf("请输入需要连接的字符个数：");
	scanf("%d",&length);

	while(*target1++ != '\0')
		;

	target1 -= 2;

	while(length--)
	{
		ch = *target1++ = *target2++;
		if(ch == '\0')
		{
			break;
		}
		if((int)ch < 0)
		{
			*target1++ = *target2++;
			*target1++ = *target2++;
		}
	}

	printf("连接后的结果是：%s\n",str1);
	return 0;
}
