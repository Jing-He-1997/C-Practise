#include <stdio.h>

int main()
{
	int array[3][4]= {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}};
	int **p = array;
	int i, j;
/*
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%d ", *((*p+i)+j));
		}
		printf("\n");
	}
*/

	// p 和 array 的跨度不同！！
	printf("p : %p, array: %p\n",p, array);
	printf("p+1 : %p, array+1 : %p\n",p+1, array+1);
	return 0;
}
