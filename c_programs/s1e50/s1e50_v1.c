/* JING
 * 1. 定义数组指针
 * */
#include <stdio.h>

typedef int (*PTR_TO_ARRAY)[3];

int main(void)
{
	int i;
	int array[3] = {1, 2, 3};
	PTR_TO_ARRAY ptr_to_array = &array;

	for(i = 0; i < 3; i++)
	{
		printf("%d\n", (*ptr_to_array)[i]);
	}

	return 0;
}
