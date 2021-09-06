#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void title(void);
int input(int n);
int random_num(int x);
void check(int x, int res);
void show(int count);

void title(void)
{
	printf("#######################\n");
	printf("# 欢迎来到猜拳小游戏! #\n");
	printf("#######################\n\n\n");
}

int input(int n)
{
	printf("请出拳（1剪刀/2石头/3布/0退出） -> ");
	while(1)
	{
		scanf("%d", &n);
		if(n >= 0 && n <= 3)
		{
			break;
		}
		else
		{
			printf("输入的数字不合法，请重新输入：");
		}
	}

	return n;
}


int random_num(int x)
{
	static int count = 0;
	srand(time(NULL)); 
	x = rand()% 3 + 1;

	return x;
}

void check(int x,int res)
{
	switch(res)
	{
		case 0:
		{
			if(x == 1)
				printf("你出剪刀，我出剪刀，咱打平!\n\n");
			if(x == 2)
				printf("你出石头，我出石头，咱打平!\n\n");
			if(x == 3)
				printf("你出布，我出布，咱打平!\n\n");
		}
		break;
		case -1:
		{
			if(x == 2)
				printf("你出石头，我出剪刀，我输了!\n\n");
			if(x == 3)
				printf("你出布，我出石头，我输了!\n\n");
		}
		break;
		case -2:
		{
			if(x == 3)
				printf("你出布，我出剪刀，我赢了!\n\n");
		}
		break;
		case 1:
		{
			if(x == 1)
				printf("你出剪刀，我出石头，我赢了!\n\n");
			if(x == 2)
				printf("你出石头，我出布，我赢了!\n\n");
		}
		break;
		case 2:
		{
			if(x == 1)
				printf("你出剪刀，我出布，我输了!\n\n");
		}
		break;		
	} 	
}

void show(int count)
{
	if(count == 0 || count == 1 || count == -2)
	{
		printf("\n\n游戏结束！！！YOU WIN！！！\n");
	}
	else
	{
		printf("\n\n游戏结束，YOU LOSE T T\n");
	}
}

int main(void)
{
	int num, x, res;
	title();
	do
	{
		num = input(num);
		if(num == 0)
		{
			break;
		}
		x = random_num(x);
		
		res = num - x;	
		check(x, res);
	}while(1);
	show(res);

	return 0;
}
