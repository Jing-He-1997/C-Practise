#include <stdio.h>


int count = 0;

int check(int i, int j, int (*queen)[8]);
void eight_queen(int col, int (*queen)[8]);

int main(void)
{
	int queens[8][8];
	int i, j;

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			queens[i][j] = 0;
		}
	}
	eight_queen(0,queens);
	return 0;
}

int check(int i, int j, int (*queen)[8])
{
	int s, t;
	
	//检查行 
	for(s = i, t = 0; t < 8; t++)
	{
		if(queen[s][t] == 1 && t != j)
		{
			return 0;
		}
	}

	//检查列
	for(t = j, s = 0; s < 8; s++)
	{
		if(queen[s][t] == 1 && s != i)
		{
			return 0;
		}
	}

	//检查左上方是否有皇后
	for(s = i-1, t = j-1; s >= 0 && t >= 0; s--, t--)
	{
		if(queen[s][t] == 1)
		{
			return 0;
		}
	}

	//检查右下方是否有皇后
	for(s = i+1, t = j+1; s < 8 && t < 8; s++, t++)
	{
		if(queen[s][t] == 1)
		{
			return 0;
		}
	}

	//检查左下方是否有皇后
	for(s = i-1, t = j+1; s >= 0 && t < 8; s--, t++)
	{
		if(queen[s][t] == 1)
		{
			return 0;
		}
	}

	//检查右上方是否有皇后
	for(s = i+1, t = j-1; s < 8 && t >= 0; s++, t--)
	{
		if(queen[s][t] == 1)
		{
			return 0;
		}
	}

	//如果全部检查都通过，则返回1
	return 1;
}

void eight_queen(int col, int (*queen)[8])
{
	int i, j;
	int row;

	if(col == 8)
	{

		printf("\n\nThis is the solution no.%2d\n\n", count+1);
		for(i = 0; i < 8; i++)
		{
			for(j = 0; j < 8; j++)
			{
				if(queen[i][j] == 1)
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
		count++;

		return;
	}

	for(row = 0; row < 8; row++)
	{
		if(check(row, col, queen))
		{
			queen[row][col] = 1;
			eight_queen(col+1, queen);
			queen[row][col] = 0;
		}
	}
}
