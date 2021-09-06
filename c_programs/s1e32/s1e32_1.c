#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int in_order(int array[], int length);
void shuffle(int array[], int length);
void bogo_sort(int array[], int length);

int in_order(int array[], int length)
{
	int i = 0;
	//确保数组按照要求的顺序排列
	while(array[i] <= array[i+1] && ++i < length-1)
		;
	if(i == length-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void shuffle(int array[], int length)
{
	int index, temp, i;
	static int t1, t2;

	srand(t1);//用srand播下种子后，一旦种子相同，产生的随机数也是相同的
	t1=rand();//用rand()刻意的将种子随机化
	
	t2 = time(NULL);//程序运行的时间
	srand(t1+t2);//用时间进行初始化，那么每次运行的时间肯定是不同的，产生的随机数也不同

//	因为srand(time(NULL))获得随机数的间隔是1秒1次
//	CPU的运算速度远比这个快，所以这样会出现重复的数字排列顺序
//	所以需要先加入一个随机数t1(静态变量)，每一次调用srand(t1)时都会产生不一样的随机数种子
//	srand(time(NULL));
	for(i = 0; i < length; i++)
	{
		index = rand()%(length - i) + i; 
		if(index!= i)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
		}
	}
	printf("排序后的结果是：");
	for(i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	putchar('\n');
}
void bogo_sort(int array[], int length)
{
	while(!in_order(array, length))
	{
		shuffle(array,length);
	}
	if(in_order(array, length) == 1)
	{
		printf("找到啦！！\n");
	}	
}
int main()
{
	int array[] = {73, 108, 111, 118, 101, 70, 105, 104, 67};
	int i, length;
	time_t begin, end;

	begin = time(NULL);

	length = sizeof(array) / sizeof(array[0]);
//	printf("length = %d\n", length);
	bogo_sort(array, length);

/*	printf("排序后的结果是：");
	for(i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	putchar('\n');
*/
	end = time(NULL);
	printf("总共耗时%ld秒\n", end - begin);

	return 0;
}
