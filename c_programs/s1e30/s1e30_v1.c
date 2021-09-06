#include <stdio.h>

char *getWord(char);

char *getWord(char c)
{
	switch(c)
	{
		case 'A': return "Apple";
		case 'B': return "Banana";
		case 'C': return "Cat";
		case 'D': return "Dog";
		default: return "Input fail";//这里都不需要break，因为return直接退出了
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
