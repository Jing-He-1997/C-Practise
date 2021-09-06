#include <stdio.h>

int main(void)
{
	struct Time
	{
		int hour;
		int minute;
		int second;
	};

	struct Date
	{
		int year;
		int month;
		int day;
		struct Time time;
	};

	struct Student
	{
		int id;
		char name[20];
		struct Date date;
	} stu = {
		123,
		"JING",
		2021,
		7,
		16,
		18,
		30,
		30
	};

	printf("ID:%d\n",stu.id);
	printf("name:%s\n",stu.name);
	printf("year:%d\n",stu.date.year);
	printf("month:%02d\n",stu.date.month);
	printf("day:%02d\n",stu.date.day);
	printf("hour:%02d\n",stu.date.time.hour);
	printf("minute:%02d\n",stu.date.time.minute);
	printf("second:%02d\n",stu.date.time.second);
	return 0;
}
