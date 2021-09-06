#include <stdio.h>

int main()
{
	//可以忽略行，但不能忽略列
	int array[][4]= {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}};
	// 跨度4 * sizeof(int), p 指向array的第一个元素{1 , 2 , 3, 4}
	int (*p)[4] = array;
	int i, j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%d ", *(*(p+i)+j));
		}
		printf("\n");
	}
	return 0;
}
