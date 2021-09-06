#include <stdio.h>

int main()
{
	char ch;
	
	printf("请输入：");

	for(;(ch = getchar()) != '\n';)
	{
		printf("%c",ch);
	}
	printf("\n");
	
	return 0;
}
