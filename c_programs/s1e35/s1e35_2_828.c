/* Produced by Jing in 2021.8.28
 * Recursion - 分治思路
 * */
#include <stdio.h>

#define MAX_NUM 64

int schedule [MAX_NUM+1][MAX_NUM+1];

void getInput(char name[][128], int num);
int arr_schedule(int begin, int num);

void getInput(char name[][128], int num)
{
	int i;

	for(i = 0; i < num; i++)
	{
		printf("请输入第%d个队伍的名字:", i+1);
		scanf("%s", name[i]);
		getchar();
	}	
}

int arr_schedule(int begin, int num)
{
	int i, j;

	if(num == 2)
	{
		// (2)[1][1] = 1, [1][2] = 2, [2][1] = 1, [2][2] = 2
		// (3)[3][1] = 3, [3][2] = 4, [4][1] = 4, [4][2] = 3
		// (6)[5][1] = 5, [5][2] = 6, [6][1] = 6, [6][2] = 5
		// (7)[7][1] = 7, [7][2] = 8, [8][1] = 8, [8][2] = 7
		schedule[begin][1] = begin;
		schedule[begin][2] = begin + 1;
		schedule[begin+1][1] = begin + 1;
		schedule[begin+1][2] = begin;
		return 0;
	}

	// (1)1,8 -> 1,4 | (2)1,4 -> 1,2(ret(2)1,4 go next) | (6)5,4 -> 5,2(ret(6)5,4 go next)
	arr_schedule(begin, num/2);
	// (3)1,4 -> 3,2(ret(3)1,4 go next) | (5)1,8 -> 5,4 | (7)5,4 -> 7,2(ret(7)5,4 go next)
	arr_schedule(begin + num/2, num/2);

	// (4)1,4(finished, ret(1)1,8) | (8)5, 4(finished, ret(1)1,8) | (9)1,8(finished Recursion)
	// =====================================
	// (4)1,4代码翻译 - 将前4列中前4行数据按要求存储
	// for(i = 3; i < 5; i++)
	// {
	//	for(j = 3; j <= 4; j++)
	//	{
	//		schedule[i][j] = schedule[i-2][j-2];
	//	}	
	// }
	// for(i = 1; i < 3; i++)
	// {
	//	for(j = 3; j <= 4; j++)
	//	{
	//		schedule[i][j] = schedule[i+2][j-2];
	//	}
	// }
	//==================================================
	//(8)5,4代码翻译 - 将前4列中后4行数据按要求存储
	// for(i = 7; i < 9;  i++)
	// {
	//	for(j = 3; j <= 4; j++)
	//	{
	//		schedule[i][j] = schedule[i-2][j-2];
	//	}
	// }
	// for(i = 5; i < 7; i++)
	// {
	//	for(j = 3; j <= 4; j++)
	//	{
	//		schedule[i][j] = schedule[i+2][j-2]
	//	}
	// }
	// ================================================
	// (9)1,8代码翻译 - 将8行中的前4列的数据存储到后4列中
	// for(i = 5; i < 9; i++)
	// {
	//	for(j = 5; j <=8; j++)
	//	{
	//		schedule[i][j] = schedule[i-4][i-4];
	//	}
	// }
	// for(i = 1; i < 5; i++)
	// {
	//	for(j = 5; j <= 8; j++)
	//	{
	//		schedule[i][j] = schedule[i+4][j-4];
	//	}
	// }
	for( i = begin + num / 2; i < begin + num; i++)
	{
		for(j = num / 2 + 1; j <= num; j++)
		{
			schedule[i][j] = schedule[i - num/2][j - num /2];
		}
	}

	for(i = begin; i < begin + num / 2; i++)
	{
		for(j = num / 2 + 1;j <= num; j++)
		{
			schedule[i][j] = schedule[i + num / 2][j - num / 2];
		}
	}
}

int main(void)
{

	int num, i ,j;
	printf("请输入参赛的队伍数量:");
	scanf("%d", &num);

	if(num & num - 1)
	{
		printf("num并不是2的N次方!\n");
		return -1;
	}

	char name[num][128];

	getInput(name, num);

	arr_schedule(1, num);

	printf("\n比赛安排如下:\n");
	printf("队伍");

	for(i = 1; i < num; i++)
	{
		printf("\t第%d天", i);
	}
	putchar('\n');	

	for(i = 1; i<= num; i++)
	{
		for(j = 1; j <= num; j++)
		{
			printf(" %s\t", name[schedule[i][j] - 1]);
		}
		putchar('\n');
	}
	return 0;
}
