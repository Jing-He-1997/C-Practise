#include <stdio.h>

int main()
{

	//int const *p :表示指针p的地址可以变，但是指针p指向的值不能变
	//int *const p :表示指针p的地址不能变，但是指针p指向的值可以变

	//const定义的变量的地址只能存放在用const定义了类型的指针中
	const int num = 100;
	const int test = 500;
	int const *p = &num; //能改变指针的地址，但不能改变指针指向的值
	p = &test;


	
	//用const定义了类型的指针可以存放一个变量的地址
	int num1 = 200;
	const int *p1 = &num1;

	const int num2 = 300;
	const int *p2 = &num2;

	const int num3 = 400;
	const int * const p3 = &num3;

	printf("*p = %d, *p1 = %d, *p2 = %d, *p3 = %d\n", *p, *p1, *p2, *p3);

	return 0;
}
