#include <stdio.h>

int main()
{
	int a, b;

	printf("输入两个整数到变量a和b中：");
	scanf("%d %d",&a, &b);//加上一个空格代表两个占位符之间是通过任何空白的符号隔开

	if(a != b)
	{
		if(a > b)
		{
			printf("%d > %d\n",a,b);
		}
		else
		{
			printf("%d < %d\n",a,b);
		}
	}
	else
	{
		printf("%d = %d\n",a,b);
	}
	return 0;
}
