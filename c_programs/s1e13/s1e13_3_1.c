#include <stdio.h>

int main()
{
	char ch;
	long long num = 0;// 若将num定义为int，在num = 10 * num + （ch - '0'）时，输入					超出范围的值num会自动转换为最大值；
			//在输出时无法实现超出范围的情况。

	printf("请输入待转换的字符串：");
	do
	{
		ch = getchar();
		if(ch >= '0' && ch <= '9')
		{
			num = 10 * num + (ch - '0');	
		}
		else
		{
			if(num)
			{
				break;
			}
		}
	}while(ch != '\n');

	if(num<= 2147483647 && num > 0)
	{
		printf("结果为：%d\n",num);
	}
	else if(num == 0)
	{
		printf("并未找到任何数值！\n");
	}
	else
	{
		printf("数据超出范围，定义无意义！\n");
	}

	return 0;
}
