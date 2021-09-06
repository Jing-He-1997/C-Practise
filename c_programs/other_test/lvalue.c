#include <stdio.h>

int main()
{
	int a = 5;
	//(a++)先将变量a的值(5)做为整个表达式的值返回，再将a自增1(a = a + 1)
	//所以这个表达式相当于：
	//++5, a = a + 1;
	//5是一个常量，不能5 = 5 + 1；
	++(a++);

	printf("a = %d\n",a);
	
	return 0;
}
