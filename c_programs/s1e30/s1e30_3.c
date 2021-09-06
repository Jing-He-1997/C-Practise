#include <stdio.h>

#define EPSINON 0.000001 //定义允许的误差
float add(float, float);
float sub(float, float);
float mul(float, float);
float divi(float, float);
float (*select(char))(float, float);

float add(float num1, float num2)
{
	return num1 + num2;
}
float sub(float num1, float num2)
{
	return num1 - num2;
}
float mul(float num1, float num2)
{
	return num1 * num2;
}
float divi(float num1, float num2)
{
	//不能对浮点数进行简单的==和!=比较，IEEE浮点数只是一个近似值
	if(num2 >= -EPSINON && num2 <= EPSINON)
	{
		printf("ERROR!!! 除法无法运算!!!!\n");
		return 0;
	}
	return num1 / num2;
}

float (*select(char op))(float num1, float num2)
{
	switch(op)
	{
		case '+': return add;
		case '-': return sub;
		case '*': return mul;
		case '/': return divi;
	}	
}

int main()
{
	float num1, num2;

	printf("请输入两个数字：");
	scanf("%f %f", &num1, &num2);
	if(num2 != 0)
	{
		printf("对这两个数字进行加减乘除后得到的结果是：%.2f %.2f %.2f %.2f\n",					select('+')(num1, num2), 									select('-')(num1, num2), 									select('*')(num1, num2), 									select('/')(num1,  num2));
	}
	else
	{
		printf("对这两个数字进行加减乘后得到的结果是：%.2f %.2f %.2f\n",
			select('+')(num1, num2), 									select('-')(num1, num2), 									select('*')(num1, num2),
		select('/')(num1, num2));
	}	
	return 0;
}
