#include <stdio.h>

int main()
{
	float a,b;
	char sym;
	
	printf("请输入式子：");
	scanf("%f %c %f",&a, &sym, &b);//&: 取址符号，也可以是引用，在这里就是引用。

	switch(sym)
	{
		case '+':
			printf("结果为%.2f\n",a + b);
			break;

		case '-':
			printf("结果为%.2f\n",a - b);
			break;

		case '*':
			printf("结果为%.2f\n",a * b);
			break;

		case '/':
			if (b != 0)
			{
				printf("结果为%.2f\n",a / b);
			}
			else
			{
				printf("除数不能为0！");
			}
			break;
		default: printf("请输入正确的运算符号！\n"); break;
	}
	return 0;
}
