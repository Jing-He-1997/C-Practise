#include <stdio.h>

void (*array[3])(void);//根据代码上下文推断出array是一个指针数组，数组中的每一个元素是
			//函数指针，该函数的参数和返回值都是void

void funcA(void)
{
	printf("I'm funcA\n");
}

void funcB(void)
{
	printf("I'm funcB\n");
}

void funcC(void)
{
	printf("I'm funcC\n");
}

int main(void)
{
	array[0] = funcA;
	array[1] = funcB;
	array[2] = funcC;

	array[0]();
	array[1]();
	array[2]();

	return 0;
}
