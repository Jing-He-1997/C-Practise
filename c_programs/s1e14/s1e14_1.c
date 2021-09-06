#include <stdio.h>

int main()
{
	printf("公斤 ———— 花费（元）：\n");

	for(int i = 1; i <= 20; i++)
	{
		int price = 23 + (i - 1) * 14;
		printf("%4d ———— %4d\n",i, price); //定义占位符的位置
	}

	return 0;
}
