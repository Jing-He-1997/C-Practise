#include <stdio.h>

#define MAX 1024

int main()
{
	char str1[2*MAX];
	char str2[MAX];

	char *target1 = str1;
	char *target2 = str2;

	printf("请输入第一个字符串：");
	fgets(str1, MAX, stdin);

	printf("请输入第二个字符串：");
	fgets(str2, MAX, stdin);
	
	char ch;
	//这个循环将target1指针定位到'\0'
	while((ch = *target1++)!= '\0')
		;
	
	target1 -= 2;//将target1指向str1中'\n'的前一个字符；
	
	//顺便覆盖了'\n'和'\0'
	while((*target1++ = *target2++)!= '\0')
		;
	
	printf("连接后的结果是：%s",str1);

	return 0;
}
