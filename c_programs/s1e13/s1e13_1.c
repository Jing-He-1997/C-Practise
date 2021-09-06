#include <stdio.h>

int main()
{
	int count = 0;
	char ch;	
	printf("请输入一行英文字母：");

	while((ch = getchar()) != '\n')//这里是将getchar()赋值给ch
	{
		if(ch >='A' && ch <= 'Z')
		{
			count = count + 1;
		}
	}

	printf("您总共输入了%d个大写字母！\n",count);
	return 0;
}
