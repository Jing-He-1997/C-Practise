#include <stdio.h>
#include <string.h>

#define MAX_LEN 21
#define MAX 128
int main()
{
	char str[MAX_LEN]=" ";
	char str1[128];
	int a = 20; 		//当输出文本超出时，最后一个字符的位置
	
	printf("请输入一行文本：");
	scanf("%[^\n]",&str1);	//读取不是\n（换行）的字符

	printf("长度为:%d\n",strlen(str1));
	if(strlen(str1)<= 20)
	{
		printf("输入的文本是：%s\n",str1);
	}
	else
	{
		for(int i = 19; i >= 0; i--)
		{
			if(str1[i]== ' ')
			{
				a = i + 1;
				break;
			}
		}
		printf("要输出的字符长度为 %d\n",a);

		strncpy(str, str1, a);

		printf("输入的文本是：%s\n",str);
	}

	return 0;
}
