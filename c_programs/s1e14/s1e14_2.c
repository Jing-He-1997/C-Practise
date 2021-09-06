#include <stdio.h>

int main()
{
	int num = 0;
	long sum = 0;
	_Bool flag = 0;
	do
	{
		printf("请输入合法的数字：");
		sum = sum + num;
		flag = scanf("%d",&num);
	}
	while(flag == 1);

	printf("结果为：%ld\n",sum);
	return 0;

	
	
}
