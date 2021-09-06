#include <stdio.h>

#define SQUARE(x) ((x) * (x))
int main(void)
{
	int x = 1;

	while(x <= 5)
	{
		//C语言默认将参数从右到左的顺序依次入栈，参数和局部变量都存放在栈中
		//第一次 1*2 = 2, x = 3
		//第二次 3*4 = 12 x = 5
		//第三次 5*6 = 30 x = 6
		printf("%d的平方是%d\n", x-1, SQUARE(x++));
	}

	return 0;
}
