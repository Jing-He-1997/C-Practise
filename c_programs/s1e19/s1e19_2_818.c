#include <stdio.h>

#define MAX 21

int main(void)
{
	
	int ch, space, i = 0;
	char str[MAX];

	space = MAX - 1; //初始化space

	printf("请输入一行文本:");
	while((ch = getchar()) != '\n')
	{
		str[i++] = ch;
		if(i == MAX - 1)
		{
			break;
		}

		if(ch ==' ')
		{
			space = i;
		}
	}

	if(i >= MAX-1)
	{
		str[space] = '\0';
	}
	else
	{
		str[i] = '\0';
	}

	printf("你输入的文本是:%s\n", str);

	return 0;
}
