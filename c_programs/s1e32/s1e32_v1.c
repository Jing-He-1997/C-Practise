#include <stdio.h>

int main(void) // c99主函数的标准格式（如果没有参数的话）
{
	int i = 100;
	{
		int i = 110;
		{
			int i = 120;
			printf("最里层的i = %d\n", i);
		}
		{
			printf("在最里层的平行层开头部分，i = %d\n", i);
			int i = 130;
			printf("最里层的平行层i = %d\n", i);
		}
		printf("第二层的i = %d\n", i);
	}
	printf("最外层的i = %d\n", i);
	return 0;	
}
