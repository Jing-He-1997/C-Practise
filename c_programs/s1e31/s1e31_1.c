#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//发牌器
//shuffle():将扑克牌的顺序打乱
//deal():扑克牌打乱后按照每人一张牌的顺序发牌
//show():根据每张牌对应的数字 一张一张的显示扑克牌
void shuffle(int array[], int length);
void deal(int array[], int player[3][14]);
void show(char name[3][40], int player[3][14]);

void shuffle(int* array, int length)
{
	int index, temp, i;

	srand(time(NULL));//能够产生不相同的随机序列

	for(i = 0; i < length; i++)
	{	//当length = 14时, rand()将在中取随机数,index就是取得的随机数+i
		index = rand() % (length - i) + i;
		// 当index = i时,无事发生
		if(index != i)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;//进行数组元素之间的值的互换操作
		}
	}
}

void deal(int array[], int player[3][14])
{
	int i, j, k = 0;
	//模拟发牌：拿一副无序的扑克牌每人轮流发一张
	for(i = 0; i < 14; i++)
	{
		for(j = 0; j < 3; j++)
		{
			player[j][i] = array[k++];
		}
	}
}

void show(char names[3][40], int player[3][14])
{
	int i, j, poker;
	for(i = 0; i < 3; i++)
	{
		printf("%s手上的牌是:", names[i]);

		for(j = 0; j < 14; j++)
		{
			poker = player[i][j];

			if(poker < 11 && poker > 0)
			{
				printf("方块%d ", poker);
			}
			else if(poker < 21 && poker > 10)
			{
				printf("梅花%d ", poker - 10);
			}
			else if(poker < 31 && poker > 20)
			{
				printf("红桃%d ", poker - 20);
			}
			else if(poker < 41 && poker > 30)
			{
				printf("黑桃%d ", poker - 30);		
			}
			else
			{
				switch(poker)
				{
					case 41: printf("方块J ");break;
					case 42: printf("方块Q ");break;
					case 43: printf("方块K ");break;
					case 44: printf("梅花J ");break;
					case 45: printf("梅花Q ");break;
					case 46: printf("梅花K ");break;
					case 47: printf("红桃J ");break;
					case 48: printf("红桃Q ");break;
					case 49: printf("红桃K ");break;
					case 50: printf("黑桃J ");break;
					case 51: printf("黑桃Q ");break;
					case 52: printf("黑桃K ");break;
					case 53: printf("小王 ");break;
					case 54: printf("大王 ");break;
				}
			}
		}
		printf("\n\n");
	}		
}

int main()
{
	int array[54];
	int player[3][14];
	int i, ch;
	char names[3][40];

	//initialization
	for(i = 0; i < 54; i++)
	{
		array[i] = i + 1;
	}

	for(i = 0; i < 3; i++)
	{
		printf("\n请输入%d玩家的名字：", i + 1);
		scanf("%s", names[i]);
	}

	do
	{
		shuffle(array, 54);
		deal(array, player);
		show(names, player);

		printf("重新洗牌(Y/N)?");
		do
		{
			ch = getchar();//过滤输入缓冲区的其他字符
		}while (ch != 'Y' && ch != 'N');
	}while(ch == 'Y');

	return 0;
}
