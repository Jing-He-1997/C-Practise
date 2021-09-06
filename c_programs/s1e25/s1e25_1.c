#include <stdio.h>

int main()
{
	int p, m, n;
	printf("请输入第一个矩阵的尺寸（M * P）：");
	scanf("%d * %d", &m, &p);
	getchar();
	printf("请输入第二个矩阵的尺寸（P * N）：");
	scanf("%d * %d", &p, &n);

	//max的表明的是打印的行数	
	int max = p;
	if(max < m)
	{
		max = m;
	}

	int i, j, k;
	int array1[m][p];
	int array2[p][n];
	int sum[m][n];

	printf("请输入第一个矩阵的值：\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < p; j++)
		{
			scanf("%d", &array1[i][j]);
		}
	}

	printf("请输入第二个矩阵的值：\n");
	for(i = 0; i < p; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &array2[i][j]);
		}
	}

	//得到sum[m][n]中每一个元素的值
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			sum[i][j] = 0;
			for(k = 0; k < p; k++)
			{
				sum[i][j] += array1[i][k]*array2[k][j];
			}
		}
	}

	//打印表达式
	for(i = 0; i < max; i++)
	{
		if(i < m)
		{
			printf("|");
			for(j = 0; j<p; j++)
			{
				printf("%2d ",array1[i][j]);
			}
			printf("|");
		}
		else
		{
			printf(" ");
			for(j = 0; j < p; j++)
			{
				printf("   ");
			}
			printf(" ");
		}
		
		if(i != (int) (max/2))
		{
			printf("   ");
		}
		else
		{
			printf(" * ");
		}

		if(i < p)
		{
			printf("|");
			for(j = 0; j < n; j++)
			{
				printf("%2d ",array2[i][j]);
			}
			printf("|");
		}
		else
		{
			printf(" ");
			for(j = 0; j < n; j++)
			{
				printf("   ");
			}
			printf(" ");
		}

		if(i != (int)(max/2))
		{
			printf("   ");
		}
		else
		{
			printf(" = ");
		}

		
		if(i < m)
		{
			printf("|");
			for(j = 0; j < n; j++)
			{
				printf("%3d ",sum[i][j]);
			}
			printf("|");
		}
		else
		{
			printf(" ");
			for(j = 0; j < n; j++)
			{
				printf("    ");
			}
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;

}
