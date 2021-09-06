#include <stdio.h>

int main()
{
	int count = 32;
	char ch;

	printf("请输入一行英文句子：");
	while((ch = getchar()) != '\n')
	{
		if(ch >='A' && ch <= 'Z')
		{
			ch = ch + count;
			//ch = ch - 'A' + 'a';
		}
		else if(ch >='a' && ch <= 'z')
		{
			ch = ch - count;
			//ch = ch - 'a' + 'A';
		}

		putchar(ch);
	}

	putchar('\n');
	return 0;
}
