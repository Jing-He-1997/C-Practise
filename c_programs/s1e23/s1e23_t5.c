#include <stdio.h>

int main()
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = (int *)(&array + 1);//直接指向了下一个数组！！！

	printf("%d\n",*(p - 6));

	return 0;
}
