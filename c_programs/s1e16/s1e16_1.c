#include <stdio.h>

int main()
{
	int year = 1;
	float res1 = 10000, res2 = 10000;

	while(year)
	{
		res1 = res1 + 10000 * 0.1;
		res2 = res2 + res2 * 0.05;
		if(res2 > res1)
		{
			printf("%d年后，黑夜的投资额超过小甲鱼！\n",year);
			break;
		}
		year++;
	}
	printf("小甲鱼的投资额是：%.2f\n",res1);
	printf("黑夜的投资额是：%.2f\n",res2);

	return 0;
}
