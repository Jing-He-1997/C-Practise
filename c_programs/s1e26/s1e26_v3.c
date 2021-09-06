#include <stdio.h>

int main()
{
	int array[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// p指向数组的的地址（数组中第一个元素的地址）
	int *p = array;
	int i;

	for(i = 0; i < 10; i++)
	{
		printf("%d ",*(p + i));
	}
	printf("\n");

	return 0;
}
