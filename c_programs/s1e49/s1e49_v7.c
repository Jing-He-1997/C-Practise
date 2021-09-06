#include <stdio.h>
#include <stdlib.h>
struct Date
{
	int year;
	int month;
	int day;
};

int main(void)
{
	struct Date *date;
	date = (struct Date *)malloc(sizeof(struct Date));

	if(date == NULL)
	{
		printf("动态内存分配失败!\n");
		exit(1);
	}
	date->year = 2021;
	date->month = 8;
	date->day = 25;
	printf("今天是%d-%d-%d\n", date->year, date->month, date->day);	

	return 0;
}
