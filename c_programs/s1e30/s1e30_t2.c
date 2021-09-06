#include <stdio.h>
char *a(char *b, void *c(int));
void(*func(int, void(*)(int)))(int);
//func是函数名，他有两个参数，一个是int类型，另一个是返回值为void类型并带有一个int类型参数的函数指针；
//func返回值是返回值为void类型，并带有一个int类型参数的函数指针
//日常写代码  不要这样折磨别人！！！！
int main()
{
	return 0;
}
