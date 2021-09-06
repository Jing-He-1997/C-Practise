#include <stdio.h>

int main()
{
	char ch;

	printf("请输入你的成绩：");
	scanf("%c",&ch);

	//case仅仅是一个标签，后面跟的应该是一个整型常量(只能是整型常量和常量表达式)
	//C中的switch语句没有简便的方法指定某个范围的值，除非该范围内的值以单独的case标签给出
	switch(ch)
	{
		case 'A':printf("您的成绩在90分-100分\n");break;
		case 'B':printf("您的成绩在80分-89分\n");break;
		case 'C':printf("您的成绩在70分-79分\n");break;
		case 'D':printf("您的成绩在60分-69分\n");break;
		case 'E':printf("您的成绩在0分-59分\n");break;
		default :printf("请输入正确的评级！！\n");
	}
	return 0;
}
