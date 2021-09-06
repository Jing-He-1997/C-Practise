#include <stdio.h>

//全局变量就可以
char str1[] = "Apple";
char str2[] = "Banana";
char str3[] = "Cat";
char str4[] = "Dog";
char str5[] = "Input Fail";
char *getWord(char);

char *getWord(char c)
{
	switch(c)
	{
		case 'A': return str1;
		case 'B': return str2;
		case 'C': return str3;
		case 'D': return str4;
		default: return str5;//这里都不需要break，因为return直接退出了
	}
}
int main()
{
	char input;
	char ch;
	printf("请输入一个字母：");
	scanf("%C",&input);
	char *str = getWord(input);
	printf("%s\n",str);

	return 0;
}
