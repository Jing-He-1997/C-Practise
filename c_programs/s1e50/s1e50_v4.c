#include <stdio.h>

typedef int (*PTR_TO_FUN)(int ,int);

//int calc(int (*)(int, int), int, int);
int calc(PTR_TO_FUN, int, int);
int add(int, int);
int sub(int, int);
PTR_TO_FUN select(char);// 首先可以得到select是一个函数,它的参数是char，它的返回值是一个指针
			      // 将函数名和参数删掉得到了(*)(int, int)
			      // 可以看出，select函数的返回值是一个返回整型并且带有两个int参数
			      // 的函数指针

int calc(PTR_TO_FUN fp, int num1, int num2)
{
	return (*fp)(num1, num2);	
}

int add(int num1,int num2)
{
	return num1 + num2;
}

int sub(int num1,int num2)
{
	return num1 - num2;
}

PTR_TO_FUN select(char op)
{
	switch(op)
	{
		case '+': return add;
		case '-': return sub;
	}
}

int main()
{
	int num1, num2;
	char op;
	PTR_TO_FUN fp;

	printf("请输入一个表达式：");
	scanf("%d%c%d",&num1, &op, &num2);

	fp = select(op);
	
	printf("%d %c %d = %d\n", num1, op, num2, calc(fp, num1, num2));
	
	return 0;
}
