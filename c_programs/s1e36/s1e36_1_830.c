#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count;

void set_num(int *num);
void show(int num, int *queens);
int check(int queen_id, int *queens);
void n_queens(int n, int num, int *queens);

void set_num(int *num)
{
	printf("请输入皇后的个数num(num < 15) -> ");
	scanf("%d", num);
}

void show(int num, int *queens)
{	
	int row, col;
	printf("This is the Solution No.%3d\n", count);

	for(row = 0; row < num; row++)
	{
		for(col = 0; col < num; col++)
		{
			if(queens[row] == col)
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
	putchar('\n');
	
}

int check(int queen_id, int *queens)
{
	int row;

	for(row = 0; row < queen_id; row++)
	{
		if(queens[row] == queens[queen_id] || 
			abs(queens[row] - queens[queen_id]) == queen_id - row)
		{
			return 0;
		}
	}

	return 1;
}

void n_queens(int n, int num, int *queens)
{
	int cur_col;

	if(n < num)
	{
		for(cur_col = 0; cur_col < num; cur_col++)
		{
			queens[n] = cur_col;
			if(check(n, queens))
			{
				n_queens(n+1, num, queens);
			}
		}
	}
	else
	{
		count++;
		show(num, queens);
	}
}

int main(void)
{
	int num, i;
	set_num(&num);

	int queens[num];

	for(i = 0; i < num; i++)
	{
		queens[i] = 0;
	}

	n_queens(0, num, queens);

	return 0;
}
