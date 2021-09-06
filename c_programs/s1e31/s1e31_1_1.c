#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//发牌游戏
//先洗牌，将牌的顺序打乱
//发牌，按照每一个人轮流发一张的顺序
//显示，将每个玩家的牌显示出来

void shuffle(int*, int);
void deal(int array[54], int player[3][14]);
void show(char name[3][40], int player[3][14]);

void shuffle(int array[54], int length)
{
	int i, index, temp;
	srand(time(NULL));
	
	for(i = 0; i < length; i++)
	{
		index = rand()%(length - i) + i;//index表示的是array[]中的位,+i的目的是确保
						//每一次index的最大值是53
		if(index != i)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
		}
	}
}

void deal(int array[54], int player[3][14])
{
	int i, j, k = 0;
	for(j = 0; j < 14; j++)
	{
		for(i = 0; i < 3; i++)
		{
			player[i][j] = array[k++];
		}
	}
}

void show(char name[3][40],int player[3][14])
{	int i, j, temp;
	for(i = 0; i < 3; i++)
	{
		printf("\n%s的手牌是: ", name[i]);
		for(j = 0; j < 14; j++)
		{
			temp = player[i][j];

			if(temp < 11 && temp > 0)
			{
				printf("方块%d ", temp);
			}
			if(temp < 21 && temp > 10)
			{
				printf("梅花%d ", temp - 10);
			}
			if(temp < 31 && temp > 20)
			{
				printf("红桃%d ", temp - 20);
			}
			if(temp < 41 && temp > 30)
			{
				printf("黑桃%d ", temp - 30);
			}
			else
			{
				switch(temp)
				{
					case 41:printf("方块J ");break;
					case 42:printf("方块Q ");break;
					case 43:printf("方块K ");break;
					case 44:printf("梅花J ");break;
					case 45:printf("梅花Q ");break;
					case 46:printf("梅花K ");break;
					case 47:printf("红桃J ");break;
					case 48:printf("红桃Q ");break;
					case 49:printf("红桃K ");break;
					case 50:printf("黑桃J ");break;
					case 51:printf("黑桃Q ");break;
					case 52:printf("黑桃K ");break;
					case 53:printf("小王 ");break;
					case 54:printf("大王 ");break;
				}
			}
			
		}
		putchar('\n');
	}	
}

int main()
{
	int array[54] = {0};
	int player[3][14];
	char name[3][40];

	int i;
	char ch;
	
	for(i = 0; i < 3; i++)
	{
		printf("\n请输入第%d位玩家的名字:", i + 1);
		scanf("%s", name[i]);
		printf("\n");
	}

	for(i = 0; i < 54; i++)
	{
		array[i] = i + 1;
	}
	do
	{	shuffle(array, 54);
		deal(array, player);
		show(name, player);
		
		printf("\n是否重新洗牌(Y/N):");
		do
		{
			ch = getchar();
		}while(ch != 'Y' && ch != 'N');//这里前面先输入其他字符，在输入Y和N也可以运行！
	}while(ch == 'Y');

	return 0;
}
