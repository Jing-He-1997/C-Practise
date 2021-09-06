#include <stdio.h>
#include <string.h>

void fibonacci(int*, int, int);

void fibonacci(int *array, int n, int i)
{
	if(2 - i < 0)
	{	
		array[n - i + 2] = array[n - i + 1] + array[n - i];
		i--;
		fibonacci(array, n, i);
	}
}

int main()
{
	int n;
	printf("请输入一个整数：");
	scanf("%d",&n);

	int array[n];
	int i = n;

	array[0] = 1;
	array[1] = 1;

	fibonacci(array, n, i);
	printf("Fibonacci数列的前10个数字是：");
	for(int j = 0; j < n; j++)
	{
		printf("%d ", array[j]);
	}
	putchar('\n');

	return 0;
}
