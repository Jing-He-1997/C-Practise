#include <stdio.h>

int main(void)
{
	enum Color {red = 10, green, blue};	//给枚举常量的第一个值赋值
	enum Color rgb;

	for(rgb = red; rgb <= blue; rgb++)
	{
		printf("rgb = %d\n", rgb);
	}
	
	return 0;
}
