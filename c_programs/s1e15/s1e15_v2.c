#include <stdio.h>

int main()
{
	int ch;
	printf("请输入一行字符：");
	
	while((ch = getchar()) != '\n')
	{
		if(ch == 'g')
		{
			continue;
		}
		putchar(ch);
	}
	putchar('\n');

	return 0;
}
