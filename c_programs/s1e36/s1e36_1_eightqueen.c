#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void show(void);
int check(int queen_id);
void eight_queen(int);

int queens[8];
int sum = 0;
int max = 8;

int main(void)
{
	eight_queen(0);
	printf("%d", sum);

	return 0;
}

void show(void)
{
	printf("\n\nThis is solution no.%2d:\n\n", sum);
	for(int row = 0; row < max; row++)
	{
		for(int column = 0; column < max; column++)
		{
			if(queens[row] == column)
			{
				printf("Q");
			}
			else
			{
				printf("*");
			}
		}
		putchar('\n');
	}
}

int check(int queen_id)
{
	for(int row = 0; row < queen_id; row++)
	{
		if(queens[row] == queens[queen_id] 
			|| abs(queens[queen_id] - queens[row]) == (queen_id - row))
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
