#include <stdio.h>

int main()
{
	float array [3][12]= {
		{0, 0, 0, 0, 0, 0, 0, 31.3, 35.5, 58.7, 49.6, 55.5},
		{59.8, 54.9, 33.1, 38.2, 26.6, 20.5, 27.8, 38.5, 41.5, 44.7, 38.1, 41.5},
		{34.9, 36.4, 47.5, 37.9, 30.6, 23.4, 26.6, 34.3, 0, 0, 0, 0}
	};

	float max = 0, min = 100, temp;
	int i, j;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 12; j++)
		{
			temp = array[i][j];
			//得到最大值和最小值
			if(temp != 0)
			{
				max = max > temp? max:temp;
				min = min < temp? min:temp;
			}
		}
	}
	printf("最小值为：%.2f, 最大值为：%.2f\n",min, max);
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j< 12; j++)
		{
			temp = array[i][j];
			//四舍五入
			if(temp - (int)temp > 0.4)
			{
				temp = temp + 1;
			}
			if(temp != 0)
			{
				printf("%d年%2d月：",i + 2014,j + 1);
				while((int)temp- (int)min> 0)
				{
					printf("*");
					temp--;
				}
				printf("\n");
			}
		}
	}
	return 0;
}
