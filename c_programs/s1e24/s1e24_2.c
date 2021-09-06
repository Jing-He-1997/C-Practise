#include <stdio.h>
#include <string.h>

#define MAX 1024
int main()
{
	char array[MAX];
	printf("请输入个字符：");
	fgets(array, MAX, stdin);
	
	int length = strlen(array);
	int i;
	for(i = 1; i< length / 2; i++)
	{
		if(length / i == i)
		{
			break;
		}
	}
	
	char (*target)[i] = (char (*)[i])&array;

	for(int j = 0; j < i; j++)
	{
		for(int k = 0; k < i; k++)
		{
			printf("%c ", *(*(target + j)+ k));
		}
		printf("\n");
	}

	return 0;
}
