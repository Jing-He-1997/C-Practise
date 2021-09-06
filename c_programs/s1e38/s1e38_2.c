#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT_MATRIX 64

void statement(void);
int get_ins(void);
int *create(void);
void matrix_init(int *ptr);
void set_value(int *ptr);
void read(int *ptr);
void print_matrix(int *ptr);

void statement(void)
{
	printf("\n================================================================\n");
	printf("* Welcome to use this Program, the instructions are as follows *\n");
	printf("* 1. Generate a N * N Matrix                                   *\n");
	printf("* 2. Initialize this Matrix                                    *\n");
	printf("* 3. Set a value to a specific element in this Matrix          *\n");
	printf("* 4. Read a specific elemnet from this Matrix                  *\n");
	printf("* 5. Print whole Matrix                                        *\n");
	printf("* 6. End the Program                                           *\n");
	printf("================================================================\n\n");
}

int get_ins(void)
{
	int ins;
	
	printf("\n请输入指令：");
	scanf("%d", &ins);

	while(ins < 1 || ins > 6)
	{
		printf("\n指令错误，请重新输入：");
		scanf("%d", &ins);
	}

	return ins;
}

int *create(void)
{
	int m, n;
	static int created = 0;
	static int *ptr = NULL;
	if(created)
	{
		printf("矩阵已存在，是否需要重新创建？(Y/N) -> ");
		getchar();
		while(getchar() == 'N');
		{
			return ptr;
		}
	}
	printf("请输入新矩阵的规模(M*N) -> ");
	scanf("%d*%d", &m, &n);

	while(m < 1 || n < 1)
	{
		printf("规模太小，请重新输入：");
		scanf("%d*%d", &m, &n);
	}

	while(m > MAX_LIMIT_MATRIX || n > MAX_LIMIT_MATRIX)
	{
		printf("规模太大，请重新输入：");
		scanf("%d*%d", &m, &n);
	}
	//这里使用realloc，支持重新创建二维数组
	//多申请两个整型空间，用来存放矩阵的长和宽
	ptr = (int *)realloc(ptr, (m * n +2) * sizeof(int));
	if(ptr ==NULL)
	{
		printf("内存申请失败！\n");
		exit(1);
	}
	
	printf("%d*%d的矩阵创建成功！\n",m, n);
	created = 1;

	//将长和宽放在前两个元素中
	ptr[0] = m;
	ptr[1] = n;

	return ptr;
}

void matrix_init(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int num, i, j;

	if(ptr == NULL)
	{
		printf("未检测到矩阵，请先生成一个矩阵！\n");
		return;
	}

	printf("请输入一个数字：");
	scanf("%d", &num);
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			matrix[i * n + j] = num;
		}
	}
}

void print_matrix(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int i, j;

	if(ptr == NULL)
	{
		printf("未检测到矩阵，请先生成矩阵！\n");
		return;
	}

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", matrix[i * n + j]);
		}
		putchar('\n');
	}
}

void set_value(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int num, x, y;

	if(ptr == NULL)
	{
		printf("未检测到矩阵，请先生成矩阵！\n");
		return;
	}

	printf("请输入需要修改的位置(ROW, COL) -> ");
	scanf("%d,%d", &x, &y);

	if(x > m || y > n || x < 1 || y < 1)
	{
		printf("坐标输入有误！\n");
		return;
	}

	printf("请输入一个数字：");
	scanf("%d", &num);

	matrix[(x - 1) * n + (y - 1)] = num;
}

void read(int *ptr)
{
	int m = ptr[0];
	int n = ptr[1];
	int *matrix = ptr + 2;
	int num, x, y;
	
	if(ptr == NULL)
	{
		printf("未检测到矩阵，请先生成矩阵！\n");
		return;
	}

	printf("请输入要读取的位置(ROW,COL) -> ");
	scanf("%d,%d", &x, &y);

	if(x > m || y > n || x < 1 || y < 1)
	{
		printf("坐标输入有误！\n");
		return;
	}

	printf("第%d行，第%d列的数字是：%d\n", x, y, matrix[(x - 1)*n + (y-1)]);
}

int main(void)
{
	int ins;
	int *ptr = NULL;

	statement();

	while((ins = get_ins()) != 6)
	{
		switch(ins)
		{
			case 1: ptr = create(); break;
			case 2: matrix_init(ptr); break;
			case 3: set_value(ptr); break;
			case 4: read(ptr); break;
			case 5: print_matrix(ptr); break;
		}
	}

	printf("\n THIS PROGRAM IS END ^ ^\n\n");
	return 0;
}
