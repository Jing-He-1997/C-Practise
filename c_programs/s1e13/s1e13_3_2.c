#include <stdio.h>
#include <math.h>

int main()
{
	char ch;
	long long num = 0;
	long long temp = 0;
	int is_overflow = 0;
	
	const int max_int = pow(2, sizeof(int) * 8) / 2 - 1; //定义max_int, const防止2									次修改
	const int min_int = (pow(2, sizeof(int) * 8) / 2) * (-1);//定义min_int

	printf("请输入待转换的字符串：");
	
	do
	{
		ch = getchar();
		if(ch >= '0' && ch <= '9')
		{
			temp = 10 * num + (ch - '0');
			if(temp > max_int || temp < min_int)
			{
				is_overflow = 1;
				break;
			}
			else
			{
				num = temp;
			}
		}
		else
		{
			if(num)
			{
				break;
			}
		}
	}
	while(ch != '\n');

	if(is_overflow)
	{
		printf("数值超出范围，结果未定义！\n");
	}
	else
	{
		if(!num)
		{
			printf("并未找到任何数值！\n");
		}
		else
		{
			printf("结果为：%d\n",num);
		}
	}
	return 0;
}
