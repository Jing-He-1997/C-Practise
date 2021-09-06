#include <stdio.h>

int main()
{
	int num = 520;
	void *p; //void 指针只保留了地址，并没有记录跨度
	
	p = &num;

	printf("%d\n", *(int *)p); //如果不指定指针的数据类型，那么编译器将会报错!

	return 0;
}
