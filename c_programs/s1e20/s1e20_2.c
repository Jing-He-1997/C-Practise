#include <stdio.h>

int main()
{
	int num;
	int m,n;
	printf("请输入A（B）矩阵的行数（列数）和列数（行数）[行数小于列数]:");
	scanf("%d %d",&m,&n);

	int a[m][n];
	int b[n][m];

	for(int i = 0;i < m;i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("请输入a[%d][%d](b[%d][%d])的值：",i,j,j,i);
			scanf("%d",&num);
			a[i][j]= num;

			b[j][i]= num;
		}
	}

	int c[m][m];
	for(int i = 0;i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{	
			c[i][j]= 0;
			for(int k = 0; k < n; k++)//该循环得到每一个变量的值
			{
				c[i][j]= c[i][j]+a[i][k]*b[k][j];
			}
		}
	}

	//以行为单位对结果进行输入
	//每一行的特定位置都要判断是否输入'|' , ' ' , '*' , '='
	for(int i = 0; i < n; i++)
	{
		if(i < m)
		{
			printf("| ");
		}
		else
		{
			printf("  ");
		}

		for(int j = 0; j< n; j++)
		{
			if(i < m)
			{
				printf("%-2d ",a[i][j]);
			}
			else
			{
				printf("   ");
			}
		}

		if(i< m)
		{
			printf("|");
		}
		else
		{
			printf(" ");
		}

		if(i == n / 2)
		{
			printf(" * ");
		}
		else
		{
			printf("   ");
		}

		printf("| ");
		for(int k = 0;k < m; k++)
		{
			printf("%-2d ",b[i][k]);
		}
		printf("|");

		if(i == n / 2)
		{
			printf("= ");
		}
		else
		{
			printf("  ");
		}

		if(i < m)
		{
			printf("| ");
		}
		else
		{
			printf("  ");
		}

		for(int l = 0; l < m; l++)
		{
			if(i < m)
			{
				printf(" %-4d ",c[i][l]);
			}
			else
			{
				printf("      ");
			}
		}

		if(i < m)
		{
			printf("|");
		}
		else
		{
			printf("  ");
		}
	
		printf("\n");
	}
	return 0;

}
