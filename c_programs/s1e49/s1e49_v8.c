#include <stdio.h>
#include <stdlib.h>
typedef struct Date
{
	int year;
	int month;
	int day;
} DATE, *PDATE;

int main(void)
{
	PDATE date;
	date = (PDATE)malloc(sizeof(DATE));

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
