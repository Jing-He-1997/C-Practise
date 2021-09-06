#include <stdio.h>

int main(void)
{
	struct Date
	{
		int year;
		int month;
		int day;
	};

	long count1 = 0, count2;	
	struct Date date1, date2, date3;
	int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	printf("请输入你的生日(yyyy-mm-dd):");
	scanf("%d-%d-%d", &date1.year, &date1.month, &date1.day);

	printf("请输入今年日期(yyyy-mm-dd):");
	scanf("%d-%d-%d", &date2.year, &date2.month, &date2.day);

	date3.year = date1.year + 100;
	date3.month = date1.month;
	date3.day = date1.day;

	while(date1.year <= date3.year)
	{
		day[1] = ((date1.year%4==0 && date1.year%100!=0)||date1.year%400==0)?29:28;
		while(date1.month <= 12)
		{
			while(date1.day <= day[date1.month - 1])
			{
				if(date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
				{
					count2 = count1;
					printf("你在这个世界上总共待了%d\n", count2);
				}
			
				if(date1.year == date3.year && date1.month == date3.month && date1.day == date3.day)
				{
					printf("如果能够活到100岁, 你还剩下%d天\n", count1 - count2);
					printf("你已经使用了%.2f\%的生命,请好好珍惜剩下的时间！\n"
						,(double) count2 / count1 * 100);
					goto FINISH;
				}
				date1.day++;
				count1++;
				
			}

			date1.day = 1;
			date1.month++;
		}

		date1.month = 1;
		date1.year++;
	}

FINISH:	return 0;
}
