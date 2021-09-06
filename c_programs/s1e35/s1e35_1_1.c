#include <stdio.h>

#define MAX 128

int schedule[MAX][MAX];

int arrange(int begin, int num);

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

	arrange(begin, num/2);		//第一个： 1,4 1,2(if后结束)
	arrange(begin + num/2, num/2);	//第二个： 5,4 (进入第一个) 5,2 (if结束后ret) --> 
					//(进入第二个) 3,2 (go if)
	for(i = begin; i < begin + num/2; i++)
	{
		for(j = num/2 + 1; j<= num; j++)
		{
			schedule[i][j] = schedule[i+num/2][j-num/2];
		}
	}

	for(i = begin + num/2; i < begin + num; i++)//i<=num, i< begin + num(为什么不能用i<=num)
	{
		for(j = num/2+1; j <= num; j++)
		{
			schedule[i][j] = schedule[i-num/2][j-num/2];
		}
	}
}
int main(void)
{
	int num, i, j;

	printf("请输入队伍的个数：");
	scanf("%d", &num);

	if(num & num - 1)
	{
		printf("参赛队伍必须时N的2次方！\n");
		return -1;
	}

	arrange(1, num);

	printf("编 号");
	for(i = 1; i < num; i++)
	{
		printf("\t第%d天", i);
	}
	putchar('\n');

	for(i = 1; i <= num; i++)
	{
		for(j = 1; j <= num; j++)
		{
			printf("%3d\t", schedule[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
