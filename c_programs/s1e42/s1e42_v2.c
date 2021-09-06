#include <stdio.h>

int main(void)
{
	struct A
	{
		//调整后
		char a;
		char c;
		int b;
	} a = {'x', 'o', 520};

	//打印结果为12 【编译器内存读取后的结果】
	printf("sizeof A = %d\n", sizeof(a));
	return 0;
}
