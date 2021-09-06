#include <stdio.h>

void quick_sort(int array[], int left, int right);

void quick_sort(int array[], int left, int right)
{
	int i = left, j = right;
	int temp, pivot;
	pivot = array[(left + right) / 2];

	while(i <= j)
	{
		while(array[i] < pivot)
		{
			i++;
		}
		while(array[j] > pivot)
		{
			j--;
		}

		if(i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}

	if(left < j)
	{
		quick_sort(array, left, j);
	}
	if(i < right)
	{
		quick_sort(array, i, right);
	}
}

int main(void)
{
	int num, i;
	printf("请输入一个整数：");
	scanf("%d", &num);

	int array[num];

	for(i = 0; i < num; i++)
	{
		printf("请输入第%d个数：",i+1);
		scanf("%d", &array[i]);
		getchar();
	}

	quick_sort(array, 0, num-1);

	printf("排序后：");
	for(i = 0; i < num; i++)
	{
		printf("%d ", array[i]);
	}
	putchar('\n');

	return 0;
}
