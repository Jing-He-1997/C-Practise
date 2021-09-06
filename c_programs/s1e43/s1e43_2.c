#include <stdio.h>
#include <math.h>

int main(void)
{
	struct Point
	{
		int x;
		int y;
		int z;
	};

	int n, i, j;
	double op_x, op_y, op_z;
	double res;
	printf("请输入需要录入的数据数量:");
	scanf("%d", &n);

	struct Point coord[n];
	
	for(i = 0; i < n; i++)
	{
		printf("\n请输入第 %d 个点的 x 坐标:", i+1);
		scanf("%d", &coord[i].x);
		printf("请输入第 %d 个点的 y 坐标:", i+1);
		scanf("%d", &coord[i].y);
		printf("请输入第 %d 个点的 z 坐标:", i+1);
		scanf("%d", &coord[i].z);
	}

	putchar('\n');

	for(i = 0; i < n-1; i++)
	{
		for(j = i+1; j < n; j++)
		{
			op_x = coord[i].x - coord[j].x;
			op_y = coord[i].y - coord[j].y;
			op_z = coord[i].z - coord[j].z;
			res = sqrt(op_x * op_x + op_y * op_y + op_z * op_z);
			printf("第 %d 个点和第 %d 个点之间的距离大约是 %.2f\n", i+1, j+1 , res);
		}
	}

	return 0;
}
