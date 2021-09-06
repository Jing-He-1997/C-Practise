#include <stdio.h>

#define MAX 1024
int main()
{
	char str1[MAX];
	char str2[MAX];

	char *target1 = str1;
	char *target2 = str2;
	_Bool flag = 1;
	int num = 1;

	int length;
	char ch;
	

	printf("请输入第一个字符串：");
	fgets(str1, MAX, stdin);

	printf("请输入第二个字符串：");
	fgets(str2, MAX, stdin);

	printf("请输入需要对比的字符个数：");
	scanf("%d",&length);

	int a = length;

	while(length && *target1!= '\0'&& *target2!='\0')
	{
		ch = *target1;
		if(ch < 0)
		{
			//当字符为汉字时，从低位开始检查汉字的前两个字符
			if(*target1++!= *target2++ || *target1++ != *target2++)
			{
				flag = 0;
				break;
			}
		}
		if(*target1++ != *target2++)
		{
			flag = 0;
			break;
		}
		num++;
		length--;
	}

	if(flag)
	{
		printf("两个字符串前%d个字符完全相同！\n",a);
	}
	else
	{
		printf("两个字符串不完全相同，第%d个字符出现不同！\n",num);
	}

	return 0;
}
