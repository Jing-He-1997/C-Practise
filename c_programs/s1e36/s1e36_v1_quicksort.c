#include <stdio.h>

void quick_sort(int array[], int left, int right);

void quick_sort(int array[], int left, int right)
{
	int i = left, j = right;
	int temp;
	int pivot;
	pivot = array[(left + right)/ 2];

	while(i <= j)
	{	
		//从左到右找到大于等于基准点的元素
		while(array[i] < pivot)
		{
			i++;
		}
		//从右到左找到小于等于基准点的元素
		while(array[j] > pivot)
		{
			j--;
		}

		//如果i < j，则互换
		if(i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			//互换完后，i和j需要继续移动
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
		printf("请输入第%d个数:", i+1);
		scanf("%d", &array[i]);
		getchar();
	}

	quick_sort(array, 0, num-1);

	for(i = 0; i < num; i++)
	{
		printf("%d ", array[i]);
	}
	putchar('\n');
	
	return 0;
}
