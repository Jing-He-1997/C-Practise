#include <stdio.h>

#define MAX 1024
int main()
{
	char array[MAX];
	printf("请输入9个字符：");
	fgets(array, MAX, stdin);

	char (*target)[3] = (char (*)[3])&array;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%c ", *(*(target + i)+ j));
		}
		printf("\n");
	}

	return 0;
}
