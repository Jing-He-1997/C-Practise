#include <stdio.h>
#include <math.h>

int main()
{
	int num;
	printf("请输入一个整数：");
	scanf("%d",&num);
	
	double res;
	res = pow(num,5);
	printf("%d的五次方是：%.2f\n", num, res);
	
	return 0;
}
