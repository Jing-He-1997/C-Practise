#include <stdio.h>
#include <math.h>

int main(void)
{
	int ch;
	long long num;
	long long temp; // 临时变量，用于测试是否超出范围
	int is_overflow = 0;

	const max_int = pow(2, sizeof(int) * 8) / 2 - 1;
	const min_int = pow(2, sizeof(int) * 8) / 2 * (-1);

	printf("请输入待转换的字符串:");
	do
	{
		ch = getchar();
		
		if(ch >= '0' && ch <= '9')
		{
			temp = num * 10 + ch - '0';
			if(temp < min_int || temp > max_int)
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
	}while(ch != '\n');

	if(is_overflow)
	{
		printf("数值超出范围，结果未定义!\n");
	}
	else
	{
		if(!num)
		{
			printf("并未找到任何数值!\n");
		}
		else
		{
			printf("结果为:%d\n", num);
		}
	}
	return 0;
}
