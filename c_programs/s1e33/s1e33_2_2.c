#include <stdio.h>
int myPrint(int num);
void createMatrix(int n);

int myPrint(int num)
{
	int flag = 1;
	printf("请输入一个奇数：");
	while(flag)
	{
		scanf("%d", &num);
		getchar();
		if(num % 2 != 0)
		{
			flag = 0;
		}
		else
		{
			printf("输入的数字不是奇数！请重新输入：");
		}
	}
	return num;
}

void createMatrix(int num)
{
	int i = 0, j = num/2, oi, oj;
	int max = num * num;
	int matrix[num][num];

	for(int row = 0; row < num; row++)
	{
		for(int col = 0; col < num; col++)
		{
			matrix[row][col] = 0;
		}
	}

	for(int count = 1; count <= max; count++)
	{
		matrix[i][j] = count; //将数字存放到matrix二维数组中
		oi = i;
		oj = j;//记录当前位置

		i = i-1;
		j = j+1;//向有上角移动一格

		//先移动，后判断是否到了边界
		if(i < 0)
		{
			i = num -1;
		}
		if(j > num - 1)
		{
			j = 0;
		}

		//再判断该位置是否已经有了数字，如果有就向下移动一个位置
		if(matrix[i][j] != 0)
		{
			i = oi + 1;
			j = oj;
		}
	}

	for(int row = 0; row < num; row++)
	{
		for(int col = 0; col < num; col++)
		{
			printf("%3d ", matrix[row][col]);
		}
		putchar('\n');
	}
}

int main(void)
{
	int num = myPrint(num);
	createMatrix(num);
	return 0;
}
