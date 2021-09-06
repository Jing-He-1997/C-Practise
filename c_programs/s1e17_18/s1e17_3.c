#include <stdio.h>

int main()
{
	long count1= 0;
	long count2= 0;
	int year1,year2;
	int month1,month2;
	int day1,day2;
	int age;
	int days[]={31,28,31,30,31,30,31,31,30,31,30,31};

	printf("请输入你的生日(yy-mm-dd)：");
	scanf("%d-%d-%d",&year1,&month1,&day1);

	printf("请输入当前日期(yy-mm-dd)：");
	scanf("%d-%d-%d",&year2,&month2,&day2);

	int year3 = year1 + 100, month3 = month1, day3 = day1;

	while(year1<= year3)
	{
		days[1]=((year1%4== 0&&year1%100!= 0)||year1%400== 0)?29:28;
		while(month1<= 12)
		{
			while(day1 <=days[month1 -1])
			{
				if(year1==year2 && month1==month2 && day1==day2)
				{
					count2 = count1;
					printf("你在这个世界上已经活了%d天\n",count2);	
				}
				if(year1==year3 && month1==month3 && day1==day3)
				{
					printf("如果活到100岁，你还剩下%d天的寿命\n",count1 - count2);
					printf("你已经消耗了%.2f%的生命\n",(double)count2/count1 * 100);
					goto FINISH;
				}
				day1++;
				count1++;
				
			}
			day1 = 1;
			month1++;
		}
		month1 = 1;
		year1++;
	}

FINISH:	return 0;
}
