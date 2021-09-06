#include <stdio.h>

int main()
{
	float a;

	printf("请输入华氏度：");
	scanf("%f",&a);

	double b = (a - 32) * 5 / 9;

	printf("转换为摄氏度是：%.2f\n",b);
	return 0;
}
