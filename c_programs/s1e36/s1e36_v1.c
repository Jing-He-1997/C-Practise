#include <stdio.h>

void quick_sort(int array[], int left, int right);

void quick_sort(int array[], int left, int right)
{
	int i = left, j = right;
	int temp;
	int pivot;

	pivot = array[(i+j)/2];

	//排序开始
	while(i <= j)
	{
		//从左到右找到比中间值大的元素
		while(array[i] < pivot)
		{
			i++;
		}
		//从右到左找到比中间值小的元素
		while(array[j] > pivot)
		{
			j--;
		}
		//但没有出现i > j的情况时，进行元素的互换
		if(i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;//前往下一个元素
			j--;//前往下一个元素
		}
	}

	//当标记位i没有超过left， 则继续排序
	if(left < j)
	{
		quick_sort(array, left, i);
	}
	//当标记位j没有超过right，则继续排序
	if(i < right)
	{
		quick_sort(array, i, right);
	}
}

int main(void)
{
	int num, i;
	printf("请输入一个整数：");
	scanf("%d",&num);

	int array[num];

	for(i = 0; i < num; i++)
	{
		printf("请输入第%d个数字：", i+1);
		scanf("%d", &array[i]);
		getchar();
	}

	quick_sort(array, 0, num-1);

	printf("排序后的数字是：");

	for(i = 0; i < num; i++)
	{
		printf("%d ", array[i]);
	}
	putchar('\n');
	return 0;
}
