#include <stdio.h>

int main()
{
	char ch[6] = "Jingg";
	int i;

	printf("请输入你想要访问的字符序号（0 - 5）：");
	scanf("%d", &i);
	
	if(i<= 5 && i >= 0)
	{
		printf("%c\n", ch[i]);
	}
	else
	{
		printf("越界了！\n");
	}

	return 0;
}
