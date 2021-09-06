/* JING
 * 2. 定义函数指针
 * */
#include <stdio.h>

typedef int (*PTR_TO_FUN)(void);

int fun(void)
{
	return 520;
}

int main(void)
{
	PTR_TO_FUN ptr_to_fun = &fun;

	printf("%d\n", (*ptr_to_fun)());

	return 0;
}
