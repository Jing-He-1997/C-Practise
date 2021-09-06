#include <stdio.h>

int main()
{
	float array [3][12]= {
		{0, 0, 0, 0, 0, 0, 0, 31.3, 35.5, 58.7, 49.6, 55.5},
		{59.8, 54.9, 33.1, 38.2, 26.6, 20.5, 27.8, 38.5, 41.5, 44.7, 38.1, 41.5},
		{34.9, 36.4, 47.5, 37.9, 30.6, 23.4, 26.6, 34.3, 0, 0, 0, 0}
	};

	int year, month;
	printf("请输入查询年月份(年-月)：");
	scanf("%d-%d",&year,&month);

	if(year<2014||year>2016||month<1||month>12)
	{
		printf("数据输入错误！\n");
	}
	else
	{
		if(array[year-2014][month-1]!= 0)
		{
			printf("%d年%d月广州的PM2.5值是：%.2f\n",year,month,array[year-2014][month-1]);
		}
		else
		{
			printf("抱歉，该月份未收录数据！\n");
		}
	}
		return 0;
}
