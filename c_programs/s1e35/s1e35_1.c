#include <stdio.h>

#define MAX_NUM 64
int schedule[MAX_NUM][MAX_NUM];

int arrange(int begin, int num);

//1,4 1,2(ret) 3,2(ret) 
int arrange(int begin, int num)
{
	int i, j;

	if(num == 2)
	{
		//最后输出时是从[1][1]开始，所以就没事
		schedule[begin][1] = begin;
		schedule[begin][2] = begin + 1;
		schedule[begin+1][1] = begin + 1;
		schedule[begin+1][2] = begin;
		return 0;
	}

	arrange(begin, num/2);
	arrange(begin + num/2, num/2);
	
	//到这里时, begin = 1, num = 4;
	//这个循环是看第三行和第四行
	for(i = begin + num/2; i < begin + num; i++)
	{
		for(j = num/2 + 1; j<begin + num; j++)
		{
			schedule[i][j] = schedule[i-num/2][j-num/2];
			//[3][3] = [1][1], [3][4] = [1][2]
		}
	}

	//这个循环是看第一行和第二行
	for(i = begin; i < begin + num/2; i++)
	{
		for(j= num/2 + 1; j <= num; j++)
		{
			schedule[i][j] = schedule[i+num/2][j-num/2];
			//[1][3] = [3][1], [1][4] = [3][2]
		}
	}
}
int main(void)
{
	int num, i, j;
	printf("请输入参赛的队伍数量：");
	scanf("%d", &num);

	//检查num是否2的N次方
	//注意这里是&， 不是&&
	//&是按位与操作， 1&1==1, 0&1==0, 0&0==0
	
	if(num & num - 1)
	{
		printf("参赛队伍的数量必须是2的N次方！\n");
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
