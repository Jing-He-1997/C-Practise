#include <stdio.h>

int main()
{
	long count = 0;
	int year1,year2;
	int month1,month2;
	int day1,day2;
	int days[]={31,28,31,30,31,30,31,31,30,31,30,31};//将每个月的天数放在数组中

	printf("请输入你的生日：(yyyy-mm-dd)");
	scanf("%d-%d-%d",&year1,&month1,&day1);

	printf("请输入当前日期：(yyyy-mm-dd)");
	scanf("%d-%d-%d",&year2,&month2,&day2);

	while(year1<= year2)//从出生日期一天天加到当前日期
	{
		days[1]=((year1%4== 0&&year1%100!= 0)||year1%400== 0)?29:28;	//判断
										//是否是闰年
		while(month1<= 12)//月的跳转
		{
			while(day1 <=days[month1 -1])//天的跳转
			{
				if(year1==year2 && month1==month2 && day1==day2)
				{
					goto FINISH;//当加到和当前年月日一样时，结束	
				}
				day1++;
				count++;
			}
			day1 = 1;//重置天数
			month1++;
		}
		month1 = 1;//重置月数
		year1++;
	}

FINISH:	printf("你在这个世界上活了%d天\n",count);
	return 0;
}
