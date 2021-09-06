#include <stdio.h>

int main()
{
	int ch;
	printf("请输入一行字符串：");

	while((ch = getchar()) != '\n')
	{
		if(ch < '0' || ch > '9')
		{
			continue;
		}
		putchar(ch);
	}
	putchar('\n');

	return 0;
}
