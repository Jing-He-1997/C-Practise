#include <stdio.h>

#define MAX 21

int main()
{
	int ch, space, i = 0;
	char str[MAX];

	space = MAX - 1;

	printf("请输入一行文本：");
	while((ch = getchar())!= '\n')
	{
		str[i++]= ch;
		if(i == MAX - 1)
		{
			break;	   //到了字符数组最后一个位置
		}

		if(ch == ' ')
		{
			space = i; //随着i++, 开始记录字符串最后一个空格的位置
		}
	}

	//如果输入字符串长度大于20个字符，则在最后20个字符前的最后一个空格处填入'\0'
	if(i >= MAX -1)
	{
		str[space] = '\0';
	}
	//否则，直接在字符串的最后一位填入'\0'
	else
	{
		str[i] = '\0';
	}

	printf("你输入的文本是：%s\n",str);

	return 0;
}
