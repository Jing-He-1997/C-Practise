#include <stdio.h>

int main()
{
	float num = 0;
	double sum = 0;
	int status;
	
	do
	{
		printf("请输入合法的数字：");
		do
		{
			sum = sum + num;
			status = scanf("%f",&num);
		//如果是以下格式的话	
		//status = scanf("%f", &num);
		//sum = sum +num;
		//那么在循环的最后一次会将最后一个值再加上一次	
		}while (getchar() != '\n' && status == 1);	
	}while(status == 1);

	printf("结果是：%.2lf\n",sum);

	return 0;
	
}
