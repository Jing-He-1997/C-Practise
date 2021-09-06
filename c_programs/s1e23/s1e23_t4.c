#include <stdio.h>

int main()
{
	int array[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int *target1 = array;
	int (*target2)[] = &array;

	printf("target1 = %p\n",target1);
	printf("target2 = %p\n",target2);

	return 0;
}
