#include <stdio.h>

#define MAX 64
void getInput(char array[][128], int num);
int arrange(int begin, int num);

int schedule[MAX][MAX];

void getInput(char array[][128], int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		printf("请输入第%d个队伍的名字：", i+1);
		scanf("%s", array[i]);
		getchar();
	}
}

int arrange(int begin, int num)
{
	int i, j;
	if(num == 2)
	{
		schedule[begin][1] = begin;
		schedule[begin][2] = begin + 1;
		schedule[begin+1][1] = begin + 1;
		schedule[begin+1][2] = begin;
		return 0; 
	}

	arrange(begin, num/2);
	arrange(begin + num/2, num/2);

	for(i = begin; i < begin + num/2; i++)
	{
		for(j = num/2 + 1; j <=num; j++)
		{
			schedule[i][j] = schedule[i+num/2][j-num/2];
		}
	}

	for(i = begin + num/2; i < begin + num; i++)
	{
		for(j = num/2 + 1; j <= num; j++)
		{
			schedule[i][j] = schedule[i-num/2][j-num/2];
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
		printf("输入的数字不是2的N次方！！\n");
		return -1;
	}
	char array[num][128];
	
	getInput(array, num);

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
			printf("%s\t", array[schedule[i][j] - 1]);
		}
		putchar('\n');
	}	
	
	return 0;
}

