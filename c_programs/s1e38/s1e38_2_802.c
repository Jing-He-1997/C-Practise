#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT_MATRIX 100

void statement(void);
int tap(void);
int *create_matrix(void);
void init_matrix(int *ptr);
void setval_matrix(int *ptr);
void readval_matrix(int *ptr);
void print_matrix(int *ptr);

void statement(void)
{
	printf("============================\n");
	printf("* 欢迎使用该程序，指令如下 *\n");
	printf("* 1. 生成一个M*N的矩阵     *\n");
	printf("* 2. 初始化矩阵            *\n");
	printf("* 3. 给矩阵中某个元素赋值  *\n");
	printf("* 4. 读取矩阵中某个元素    *\n");
	printf("* 5. 打印整个矩阵          *\n");
	printf("* 6. 结束程序              *\n");
	printf("============================\n");
}

int tap(void)
{
	int ins;
	int ret;
	printf("请输入指令：");
	while(1)
	{
		ret = scanf("%d", &ins);
		if(ret != 1)
		{
			printf("输入格式错误，请重新输入：");
			setbuf(stdin, NULL);	//使stdin输入流由默认缓冲区转为无缓冲区
						//这样scanf输入完毕后，缓冲区内的东西就消失了
		}
		else
		{
			if(ins >= 1 && ins <= 6)
			{
				return ins;
			}
			else
			{
				printf("您输入错误指令！！！请重新输入：");
			}
		}
	}
}

int *create_matrix(void)
{
	int m, n;
	static int created = 0;
	static int *ptr = NULL;

	if(created)
	{
		printf("矩阵已存在，是否需要重新构建? (Y/N) ->");
		getchar();

		while(getchar() == 'N')
		{
			return ptr;
		}
	}

	printf("请输入新矩阵的规模(M*N):");
	int ret = scanf("%d*%d", &m, &n);

	while (ret != 2)
	{
		setbuf(stdin, NULL);
		printf("输入格式错误！！请重新输入：");
		ret = scanf("%d*%d", &m, &n);	
	}

	while(m < 1 || n < 1)
	{
		printf("规模太小，请重新输入：");
		ret = scanf("%d*%d", &m, &n);	
	}

	while(m > MAX_LIMIT_MATRIX || n > MAX_LIMIT_MATRIX)
	{
		printf("规模太大，请重新输入：");
		ret = scanf("%d*%d", &m, &n);	
	}
	ptr = (int *)realloc(ptr, sizeof(int) * (m * n + 2));
	if(ptr == NULL)
	{
		printf("申请动态内存失败！\n");
		exit(1);
	}

	printf("%d*%d的矩阵创建成功！\n", m, n);
	created = 1;

	ptr[0] = m;
	ptr[1] = n;

	return ptr;
}

void init_matrix(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int num;
	int *matrix = ptr + 2; //此时matrix的入口地址(matrix[0] -> ptr[2])
	int i, j;

	if(ptr == NULL)
	{
		printf("未检测到矩阵，请先生成一个矩阵！\n");
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
	int num, x, y;

	if(ptr == NULL)
	{
		printf("未检测到矩阵，请先生成一个矩阵！\n");
		return ;
	}

	printf("请输入要读取的位置(行,列) ->");
	scanf("%d,%d", &x, &y);

	while(x > m || y > n || x < 1 || y < 1)
	{
		printf("坐标输入有误！\n");
		return ;
	}

	printf("请输入一个数字：");
	scanf("%d", &num);

	matrix[(x-1)*n + (y-1)] = num;
}

void readval_matrix(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int x, y;

	if(ptr == NULL)
	{
		printf("未检测到矩阵，请先生成一个矩阵！\n");
		return ;
	}

	printf("请输入要读取的位置(行,列) ->");
	scanf("%d,%d", &x, &y);

	while(x > m || y > n || x < 1 || y < 1)
	{
		printf("坐标输入有误！\n");
		return ;
	}
	
	printf("第%d行，第%d列的数字是：%d\n", x, y, matrix[(x-1)*n + (y-1)]);

}

void print_matrix(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int i, j;
	
	if(ptr == NULL)
	{
		printf("未检测到矩阵，请先生成一个矩阵！\n");
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
	int ins;
	int *ptr = NULL;

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
	printf("\n程序运行结束，感谢您的使用！\n");		
	free(ptr); //最后，别忘记了要释放分配的空间！
	return 0;
}
