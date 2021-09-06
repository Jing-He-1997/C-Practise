#include <stdio.h>

#define MAX 64

int schedule[MAX][MAX];

void getInput(char name[][128], int num);
int arrange(int begin, int num);

void getInput(char name[][128], int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		printf("请输入第%d个队伍的名字：", i+1);
		scanf("%s",name[i]);
		getchar();
	}
}

int arrange(int begin, int num)
{
	int i, j;
	if(num == 2)
	{
		schedule[begin][1] = begin;
		schedule[begin][2] = begin+1;
		schedule[begin+1][1] = begin+1;
		schedule[begin+1][2] = begin;
		return 0;
	}

	arrange(begin, num/2);
	arrange(begin + num/2, num/2);

	for(i = begin + num/2; i < begin + num; i++)
	{
		for(j = num/2 + 1; j <= num; j++)
		{
			schedule[i][j] = schedule[i-num/2][j-num/2];
		}
	}

	for(i = begin; i< begin + num/2; i++)
	{
		for(j = num/2+1; j <= num; j++)
		{
			schedule[i][j] = schedule[i+num/2][j-num/2];
		}
	}
}
int main(void)
{
	int num, i, j;
	printf("请输入参赛队伍的个数：");
	scanf("%d", &num);

	if(num & num -1)
	{
		printf("输出的参赛队伍必须是2的N次方！！");
		return -1;
	}
	
	char name[num][128];
	getInput(name, num);

	printf("\n 比赛的时间安排如下:\n");

	printf("队 伍");

	for(i = 1; i < num; i++)
	{
		printf("\t第%d天", i);
	}
	putchar('\n');

	arrange(1, num);

	for(i = 1; i <= num; i++)
	{
		for(j = 1; j <= num; j++)
		{
			printf("%s\t", name[schedule[i][j]-1]);
		}
		putchar('\n');
	}
	return 0;
}
