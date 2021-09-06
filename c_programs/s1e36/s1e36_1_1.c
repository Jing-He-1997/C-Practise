#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int queen[8];
int sum = 0;
int max = 8;

void show(void);
int check(int queen_id);
void eight_queen(int n);

int main(void)
{
	eight_queen(0);
	printf("\n一共有%d种排序方法\n", sum);
	return 0;
}

void show(void)
{
	int i, j;
	printf("\n\n This is Solution No.%2d\n\n", sum);
	for(i = 0; i < max; i++)
	{
		for(j = 0; j < max; j++)
		{
			if(queen[i] == j)
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

int check(int queen_id)
{
	int row;
	for(row = 0; row < queen_id; row++)
	{
		if(queen[row] == queen[queen_id] || 
		abs(queen[queen_id] - queen[row]) == (queen_id - row))
		{
			return 0;
		}
	}
	return 1;
}

void eight_queen(int n)
{
	if(n < max)
	{
		for(int cur_col = 0; cur_col < max; cur_col++)
		{
			queen[n] = cur_col;
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

