#include <stdio.h>

extern int count;// 在这里， count只是一个声明，不加extern也不会报错，但是为了代码清晰还是加extern

void func(void)
{
	printf("count = %d\n", count);
}
