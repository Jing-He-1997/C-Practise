#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT_MATRIX 100

void statement(void);
int tap(void);
int *create_matrix(void);
void init_matirx(int *ptr);
void setval_matrix(int *ptr);
void readval_matrix(int *ptr);
void print_matrix(int *ptr);

void statement(void)
{
	printf("\n==============================\n");
	printf("* 欢迎使用该程序，指令如下   *\n");
	printf("* 1. 生成一个M*N的矩阵       *\n");
	printf("* 2. 初始化矩阵              *\n");
	printf("* 3. 给矩阵中某个元素赋值    *\n");
	printf("* 4. 读取矩阵中某个元素      *\n");
	printf("* 5. 打印整个矩阵            *\n");
	printf("* 6. 结束程序                *\n");
	printf("==============================\n");	
}

int tap(void)
{
	int ins, ret;
	printf("\n\n请输入指令：");
	while(1)
	{
		ret = scanf("%d", &ins);
		if(ret != 1)
		{
			setbuf(stdin, NULL);
			printf("数据格式输入错误！重新输入：");
		}
		else
		{
			if(ins < 1 || ins > 6)
			{
				printf("输入的指令错误！");
			}
			else
			{
				return ins;
			}
		}
	}
}

int *create_matrix(void)
{
	static int *ptr = NULL;
	static int created = 0;
	int ret;	
	int m, n;

	if(created)
	{
		printf("矩阵已存在，是否需要重新创建? (Y/N) -> ");
		
		if(getchar() == 'N')
		{
			return ptr;
		}
	}

	printf("请输入新矩阵的规模(M*N) -> ");
	ret = scanf("%d*%d", &m, &n);

	while(ret != 2)
	{
		setbuf(stdin, NULL);
		printf("输入数据类型有错误，请重新输入：");
		ret = scanf("%d*%d", &m, &n);
	}
	while(m < 1 || n < 1)
	{
		printf("矩阵规模太小！请重新输入：");
		ret = scanf("%d*%d", &m, &n);
	}

	while(m > MAX_LIMIT_MATRIX || n > MAX_LIMIT_MATRIX)
	{
		printf("矩阵规模太大！请重新输入：");
		ret = scanf("%d*%d", &m, &n);
	}

	ptr = (int *)realloc(ptr, sizeof(int) * (m*n+2));
	if(ptr == NULL)
	{
		printf("动态内存分配失败！\n");
		exit(1);
	}

	printf("%d*%d的矩阵创建成功！\n", m, n);
	ptr[0] = m;
	ptr[1] = n;
	created = 1;

	return ptr;
}

void init_matrix(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int num, i, j;

	if(ptr == NULL)
	{
		printf("未检测到矩阵，请先创建一个矩阵！\n");
		return ;
	}

	printf("请输入一个数字：");
	scanf("%d", &num);

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			matrix[i*n + j] = num;
		}
	}
}

void setval_matrix(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int ret, num, x, y;

	if(ptr ==NULL)
	{
		printf("未检测到矩阵，请先创建一个矩阵！\n");
		return ;
	}

	printf("请输入要修改的位置(行,列) -> ");
	ret = scanf("%d,%d", &x, &y);
	
	while(ret != 2)
	{
		setbuf(stdin, NULL);
		printf("输入的数据类型有错误！请重新输入：");
		ret = scanf("%d, %d", &x, &y);
	}

	while(x < 1 || y < 1 || x > m || y > n)
	{
		printf("未能找到该行或该列！请重新输入：");
		ret = scanf("%d, %d", &x, &y);
	}

	printf("请输入一个数字：");
	scanf("%d", &num);

	matrix[(x - 1)*n + (y-1)] = num;	
}


void readval_matrix(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int ret, x, y;

	if(ptr ==NULL)
	{
		printf("未检测到矩阵，请先创建一个矩阵！\n");
		return ;
	}
	

	printf("请输入要修改的位置(行,列) -> ");
	ret = scanf("%d,%d", &x, &y);
	
	while(ret != 2)
	{
		setbuf(stdin, NULL);
		printf("输入的数据类型有错误！请重新输入：");
		ret = scanf("%d, %d", &x, &y);
	}

	while(x < 1 || y < 1 || x > m || y > n)
	{
		printf("未能找到该行或该列！请重新输入：");
		ret = scanf("%d, %d", &x, &y);
	}

	printf("第%d行，第%d列的数字是:%d\n", x, y, matrix[(x-1)*n + (y-1)]);
}

void print_matrix(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int i, j;

	if(ptr ==NULL)
	{
		printf("未检测到矩阵，请先创建一个矩阵！\n");
		return ;
	}

	for(i = 0; i < m; i++)	
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", matrix[i*n + j]);
		}
		putchar('\n');
	}
}

int main(void)
{
	statement();
	int *ptr = NULL;
	int ins;
	while((ins = tap()) != 6)
	{
		switch(ins)
		{
			case 1: ptr = create_matrix();break;
			case 2: init_matrix(ptr);break;
			case 3: setval_matrix(ptr);break;
			case 4: readval_matrix(ptr);break;
			case 5: print_matrix(ptr);break;
		}
	}

	printf("\n程序运行结束！\n");
	free(ptr);
	return 0;
}

