#include <stdio.h>

int main()
{
	char ch;
	printf("请输入一行英语：");
	while((ch = getchar()) != '\n')
	{
		if((ch >= 'A' && ch <= 'W') || (ch >= 'a' && ch <= 'w'))
		{
			ch = ch + 3;
		}
		else if(ch == 'Y'||ch =='y'||ch == 'x'||ch == 'X'||ch == 'z'||ch =='Z')
		{
			ch = ch - 23;
		}
		putchar(ch);
	}
	putchar('\n');

	return 0;
}
