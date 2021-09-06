#include <stdio.h>

int main()
{
	char str;
	
	printf("输入一个字符：");
	scanf("%c",&str);

	if(str>= 65 && str <= 90)
	{
		char str1 = str + 32;
		printf("输出为:%c\n",str1);
	}
	else if(str >= 97 && str <= 122)
	{
		char str1 = str - 32;
		printf("输出为：%c\n",str1);
	}
	else
	{
		printf("输出为：%c\n",str);
	}

	return 0;
}
