#include <stdio.h>

int main()
{
	int num;
	_Bool flag = 1;
	printf("请输入一个字符：");
	flag = scanf("%d",&num);

	if(flag)
	{
		printf("flag为1");
	}
	return 0;
}
