#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//N皇后问题

int sum = 0;//用来记录有多少种排序方法

int set_num(int num);
void show(int num, int *queens);
int check(int queen_id, int *queens);
void n_queens(int n, int num, int *queens);

int main(void)
{	int num = set_num(num);
	int queens[num];

	for(int i = 0; i < num; i++)
	{
		queens[i] = 0;
	}

	n_queens(0, num, queens);
	printf("一共有%d种排序方法\n", sum);
	return 0;
}

int set_num(int num)
{
	int flag = 1;
	printf("请输入需要排序的皇后个数(num < 15):");
	while(flag)
	{
		scanf("%d", &num);
		getchar();
		if(num >= 15)
		{
			printf("输入的数字不符合规定！！请重新输入：");
		}
		else
		{
			break;
		}
	}

	return num;
}

void show(int num, int *queens)
{

	printf("\nThis is Solution No.%3d\n", sum);
	for(int row = 0; row < num; row++)
	{
		for(int col = 0; col < num; col++)
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

void n_queens(int n, int num, int *queens)
{
	if(n < num)
	{
		for(int cur_col = 0; cur_col < num; cur_col++)
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
		sum++;
		show(num, queens);
	}
}
