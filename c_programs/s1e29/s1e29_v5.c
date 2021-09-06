#include <stdio.h>
#include <stdarg.h>

int sum (int, ...);// ...说明参数的个数不确定

int sum(int n, ...)
{
	int i, sum = 0;
	va_list vap;//定义一个变量参数列表
	va_start(vap, n);//初始化列表

	for(i = 0; i<n; i++)
	{
		sum += va_arg(vap, int);//获取每一个可变参数的值 
	}
	va_end(vap);//关闭参数列表

	return sum;
}
int main()
{
	printf("%d\n",sum(10, 1,2,3,4,5,6,7,8,9,10));
	return 0;
}
