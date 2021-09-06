#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int queens[8];//用来存放列数
int sum = 0;//用来计算一共有多少种摆位方法
int max = 8;

void show(void);
int check(int quick_id);
void eight_queen(int n);

int main(void)
{
	eight_queen(0);
	printf("\n一共有%d种摆位方法\n", sum);

	return 0;
}

//用来打印每一种摆位方法
void show(void)
{
	printf("\n\nThis is Solution No.%2d", sum);

	for(int row = 0; row < max; row++)
	{
		for(int column = 0; column < max; column++)
		{
			if(queens[row] == column)
			{
				printf("Q ");
			}
			else
			{
				printf("* ");
			}
		}
		putchar('\n');
	}
}

//检查列和两个对角线	
int check(int queen_id)
{
	for(int row = 0; row < queen_id; row++)
	{
		if(queens[row] == queens[queen_id] ||
		abs(queens[row] - queens[queen_id]) == queen_id - row)
		{
			return 0;
		}
	}
	return 1;
}

//摆放皇后，使用回溯法(递归函数)，如果能够到了第八行则记录并输出
void eight_queen(int n)
{
	if(n < max)
	{
		for(int cur_col = 0; cur_col < max; cur_col++)
		{
			queens[n] = cur_col;
			if(check(n))
			{
				eight_queen(n+1);
			}
		}
	}
	else
	{
		sum++;
		show();
	}
}
