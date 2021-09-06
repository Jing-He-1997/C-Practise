#include <stdio.h>

#define ROW 8
#define COL 8

int chess[ROW][COL];

int next(int *px, int *py, int count);
int setHorse(int x, int y, int tag);

int next(int *px, int *py, int count)
{
	int x = *px;
	int y = *py;

	switch(count)
	{
	case 0:
		if(x+2 <= ROW-1 && y-1 >= 0 && chess[x+2][y-1] == 0)
		{
			*px = x+2;
			*py = y-1;
			return 1;
		}
		break;
	case 1:
		if(x+2 <= ROW-1 && y+1 <= COL-1 && chess[x+2][y+1] == 0)
		{
			*px = x+2;
			*py = y+1;
			return 1;
		}
		break;
	case 2:
		if(x+1 <= ROW-1 && y-2 >= 0 && chess[x+1][y-2] == 0)
		{
			*px = x+1;
			*py = y-2;
			return 1;
		}
		break;
	case 3:
		if(x+1 <= ROW-1 && y+2 <= COL-1 && chess[x+1][y+2] == 0)
		{
			*px = x+1;
			*py = y+2;
			return 1;
		}
		break;
	case 4:
		if(x-2 >= 0 && y-1 >= 0 && chess[x-2][y-1] == 0)
		{
			*px = x-2;
			*py = y-1;
			return 1;
		}
		break;
	case 5:
		if(x-2 >= 0 && y+1 <= COL-1 && chess[x-2][y+1] == 0)
		{
			*px = x-2;
			*py = y+1;
			return 1;
		}
		break;
	case 6:
		if(x-1 >= 0 && y-2 >= 0 && chess[x-1][y-2] == 0)
		{
			*px = x-1;
			*py = y-2;
			return 1;
		}
		break;
	case 7:
		if(x-1 >= 0 && y+2 <= COL-1 && chess[x-1][y+2] == 0)
		{
			*px = x-1;
			*py = y+2;
			return 1;
		}
		break;
	}

	//如果上述情况均不满足当前条件
	return 0;
}

int setHorse(int x, int y, int tag)
{
	int x1 = x, y1 = y, flag = 0, count = 0;

	//用tag记录轨迹
	chess[x][y] = tag;
	//当tag等于64时，退出该函数
	if(tag == ROW * COL)
	{
		return 1;
	}

	//如果case 0可以走，则flag = 1
	flag = next(&x1, &y1, count);
	//如果不可以走，则寻找其他的case，直到循环结束为止
	while(flag == 0 && count < 7)
	{
		count += 1;
		flag = next(&x1, &y1, count);
	}

	//递归，进入下一个坐标
	while(flag)
	{
		//当成功找到所有落脚点时，返回1
		if(setHorse(x1, y1, tag+1))
		{
			return 1;
		}

		//如果没有找到所有落脚点，则回溯到上一步重新找下一个位置再走一遍
		x1 = x;
		y1 = y;
		count += 1;
		flag = next(&x1, &y1, count);
		while(flag == 0 && count < 7)
		{
			count+=1;
			flag = next(&x1, &y1, count);
		}
	}

	if(flag == 0)
	{
		chess[x][y] = 0;
	}

	return 0;		
}

int main(void)
{
	int i, j;
	for(i = 0; i < ROW; i++)
	{
		for(j = 0; j < COL; j++)
		{
			chess[i][j] = 0;
		}
	}

	if(setHorse(2, 0, 1))
	{
		for(i = 0; i < ROW; i++)
		{
			for(j = 0; j < COL; j++)
			{
				printf("%02d ", chess[i][j]);
			}
			putchar('\n');
		}
	}
	else
	{
		printf("无解！！！\n");
	}
	return 0;
}


