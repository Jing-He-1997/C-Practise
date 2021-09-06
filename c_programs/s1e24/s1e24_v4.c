#include <stdio.h>

int main()
{
	int array[][3]= {{1, 2, 3}, {4, 5, 6}};

	int  (*p)[3] = array;

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%p ",&p[i][j]);
		}
		printf("\n");
	}

	printf("p = %p\n", p);
	printf("array = %p\n", array);
	printf("*p = %p\n", *p);
	printf("*array = %p\n",*array);
	printf("array[0] = %p\n",array[0]);
	printf("array[0][0] = %p\n",&array[0][0]);
	
	return 0;
}
