#include <stdio.h>
#include <string.h>

//利用编程实现魔法方阵
//1. 将1放在第一行中间

//2. 从2开始直到n*n的各数依次按下列规则存放：45度角方向走一格，即每一个数存放的行比前一个数的行数减1，列数加1

//3. 如果行列范围超出矩阵范围，则回绕。例如1在第一行，则2应该放在最下一行，列数同样减1；
//
//4. 如果按上面规则确定的位置上已经有数，或上一个数是第1行第n列时，则把下一个数放在上一个数的下面
void createMatrix(int n);

void createMatrix(int n)
{
	int i, j, oi, oj, num, max;

	//创建一个存放矩阵的二维数组
	int matrix[n][n];

	//填充为0
	max = n*n;
	memset(matrix, 0, max * sizeof(int));

	//将1存放到第0行的中间位置
	matrix[0][n/2]= 1;

	//记录当前的行号和列号
	i = 0;
	j = n/2;

	for(num = 2; num <= max; num++)
	{
		//记住当前位置
		oi = i;
		oj = j;

		//向右上角走一步
		i = i - 1;
		j = j + 1;

		if(i < 0)
		{
			i = n -1;
		}
		if(j > n - 1)
		{
			j = 0;
		}

		if(matrix[i][j]!=0)
		{
			i = oi + 1;
			j = oj;
		}

		matrix[i][j] = num;
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%4d   ", matrix[i][j]);
		}
		putchar('\n');
	}
}

int main(void)
{
	int n;

	printf("请输入一个奇数：");
	scanf("%d",&n);

	while(!(n%2) || n < 3)
	{
		printf("输入错误，必须是一个大于2的奇数！\n");
		printf("请重新输入：");
		scanf("%d", &n);
	}

	createMatrix(n);

	return 0;
}
