#include <stdio.h>
#define F(n) 2*n
int main()
{
	int a= F(3+2);  //宏定义是在程序编译时先进行的预处理
			//其做法是直接将标识符替换成常量，并不会进行相关运算
			//因此F（3+2）= 3*2 + 2
	printf("结果为：%d\n",a);
	
	return 0;
}
