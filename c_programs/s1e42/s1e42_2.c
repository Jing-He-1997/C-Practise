#include <stdio.h>
#include <math.h>

int main(void)
{
	struct Coord
	{
		float x;
		float y;
	};

	struct Coord coord1;
	struct Coord coord2;

	printf("请输入第一个点的 x 坐标:");
	scanf("%f", &coord1.x);
	printf("请输入第一个点的 y 坐标:");
	scanf("%f", &coord1.y);
	printf("请输入第二个点的 x 坐标:");
	scanf("%f", &coord2.x);
	printf("请输入第二个点的 y 坐标:");
	scanf("%f", &coord2.y);

	double dist_x = (double)(coord1.x - coord2.x);
	double dist_y = (double)(coord1.y - coord2.y);

	double dis = dist_x * dist_x + dist_y * dist_y;
	double result = sqrt(dis);

	printf("两点之间的距离:%.2f\n", result);
	
	return 0;
}
