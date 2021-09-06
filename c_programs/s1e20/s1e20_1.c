#include <stdio.h>

int main()
{
	int a[4][5]={
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}};

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			printf("%02d ",a[i][j]);
			if(j + i == 3)
			{
				printf("\n");
			}
		}
	}
	printf("\n");
	//如何获取二维数组的长度
	int length = sizeof(a) / sizeof(a[0][0]);
	printf("\nThe length of a[][] is %d\n", length);

	return 0;
}
