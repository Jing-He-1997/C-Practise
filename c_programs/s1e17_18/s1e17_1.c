#include <stdio.h>

int main()
{
	int a[12],year;
	
	printf("请输入一个年份：");
	scanf("%d",&year);

	for(int i = 0; i < 12; i++)
	{
		if(i== 0||i== 2||i== 4||i== 6||i== 7||i== 9||i==11)
		{
			printf("%-2d月份：31天\n",i + 1);
		}
		if(i== 1)
		{
			if((year%4== 0&&year%100!= 0)||year%400== 0)
			{
				printf("%-2d月份：29天\n",i + 1);
			}
			else
			{
				printf("%-2d月份：28天\n",i + 1);
			}
		}
		if(i== 3||i== 5||i== 8||i== 10)
		{
			printf("%-2d月份：30天\n",i + 1);
		}
	}

	return 0;
}
