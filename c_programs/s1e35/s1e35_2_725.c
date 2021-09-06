#include <stdio.h>

#define MAX 64

int team_num(int num);//输入参赛队伍数量
void team_name(char name[][MAX], int num);//输入每个参赛队伍的名称
int arrange(int begin, int num);//对每个参赛队伍进行排序
int show(char name[][MAX], int num);//将结果打印出来

int schedule[MAX][MAX];

int team_num(int num)
{
	int flag = 1;
	printf("请输入参赛的队伍数量：");
	while(flag)
	{
		scanf("%d", &num);
		getchar();
		if(num & num -1)
		{
			printf("参赛队伍数量必须是2的N次方！！请输入正确的数字:");
		}
		else
		{
			flag = 0;
		}
	}

	return num;
	
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

	//回溯法(递归函数)
	arrange(begin, num/2);
	arrange(begin + num/2, num/2);

	for(i = begin; i <begin + num/2; i++)
	{
		for(j = num/2 + 1; j <= num; j++)
		{
			schedule[i][j] = schedule[i + num/2][j -num/2];
		}
	}

	for(i = begin + num/2; i < begin + num; i++)
	{
		for(j = num/2 + 1; j <= num; j++)
		{
			schedule[i][j] = schedule[i - num/2][j - num/2];
		}
	}	
}
void team_name(char name[][MAX], int num)
{
	for(int i = 0; i < num; i++)
	{
		printf("请输入第%d个参赛队伍的名字：", i+1);
		scanf("%s", name[i]);
		getchar();
	}
}

int show(char name[][MAX], int num)
{
	printf("\n\n比赛安排如下：\n");
	printf("队 伍");
	for(int i = 1; i < num; i++)
	{
		printf("\t第%d天", i);
	}
	putchar('\n');
	for(int i = 1; i <= num; i++)
	{
		for(int j = 1; j <= num; j++)
		{
			printf("%s\t", name[schedule[i][j]-1]);
		}
		putchar('\n');
	}

	return 0;
}


int main(void)
{
	int num = team_num(num);
	char name[num][MAX];
	team_name(name, num);
	arrange(1, num);
	show(name, num);

	return 0;
}
