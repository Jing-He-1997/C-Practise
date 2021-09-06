#include <stdio.h>

int square(int);

int square(int num)
{
	return num * num;
}

int main()
{
	int num;
	int (*fp)(int); //函数指针

	printf("请输入一个数字：");
	scanf("%d",&num);

	fp = square;// c语言中，函数名在编译器中被编译为地址，所以square是地址
			//也可以写成 fp = &square

	printf("%d * %d = %d\n", num, num, (*fp)(num));//最后一个变量也可以写成fp(num)
							//最好是写成(*fp)(num) 一下看出fp是指针

	return 0;
}
