#include <stdio.h>

//先取得魔法矩阵第一行的数
//随后根据每列的规律以列为外循环进行输出
int n;

void first_line(int *array, int num);
void magic_matrix(int array[n][n], int *array1, int num);

void first_line(int *array, int num)
{
	int i, j = 0, temp;
	int array_1[num*num];
	int array_2[num];

	for(i = 0; i < num*num; i++)
	{
		array_1[i] = i+1;//得到矩阵内的所有数
	}

	//得到魔法矩阵第一行的数
	for(i = 0; i < num; i++)
	{
		array_2[i] = array_1[j];
		if(i != num/2)
		{
			j+=num + 2;
		}
		else
		{
			j+=2;
		}
	}

	//将魔法矩阵第一行的数字进行排序
	for(i = 0; i < num; i++)
	{
		if(i >=  num/2)
		{	
			array[i] = array_2[(temp++)];
		}
		else
		{
			array[i] = array_2[i+num/2+1];
		}		
	}
		
}

void magic_matrix(int array[n][n],int *array1, int num)
{
	int i, j ,temp;
	int sum = num * num;
	int add = num + 1;//在每一列中，上一个数字 + add = 下一个数字
	int count = num - 1;//在每一列中，上一个数字 + 1 = 下一个数字(count是标记这个数字的位置)

	//将first_line方法中得到的数字放入魔法矩阵中
	for(i = 0; i < num; i++)
	{
		array[0][i] = array1[i];
	}

	// 获得魔法矩阵的每一列中的数字
	for(j = 0; j < num; j++)
	{	//只有中间那一列是没有 ’上一个数字+1 = 下一个数字‘ 的情况
		if(j == num/2)
		{
			count = num - 2;
		}
		for(i = 1; i < num; i++)
		{
			//存放上一行的数字
			temp = array[i - 1][j];
			if(temp + add > sum)
			{
				//如果当前处在count标记位时， + 1
				if(i == count && j != num/2)
				{
					array[i][j] = temp + 1;
					count -= 2;
				}
				else
				{
					array[i][j] = temp + add - sum;
				}
			}
			else
			{	
				if(i == count && j != num/2)
				{
					array[i][j] = temp + 1;
					count -= 2;
				}
				else
				{
					array[i][j] = temp + add;
				}
			}
		}
	}
}


int main()
{
	int num, i, j;
	int res = 1;
	_Bool flag = 1;
	printf("请输入一个奇数:");
	while(flag)
	{	scanf("%d", &num);
		if(num % 2 != 0)
		{
			flag = 0;
		}
		else
		{
			printf("输入错误！请重新输入:");
		}
	}
	n = num;
	int array_firstline[n];
	int array[n][n];

	first_line(array_firstline, n);

	printf("\nAfter calling magic_matrix():\n");
	magic_matrix(array, array_firstline, num);

	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < num; j++)
		{
			printf("%3d ", array[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

