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

	struct Student *pt;
	pt = &stu;
	printf("%02d:%02d:%02d\n", pt->date.time.hour, pt->date.time.minute, pt->date.time.second);
	return 0;
}
