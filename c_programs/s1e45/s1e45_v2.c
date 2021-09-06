#include <stdio.h>

struct Date
{
	int year;
	int month;
	int day;
};

struct Book
{
	char title[128];
	char author[40];
	float price;
	struct Date date;
	char publisher[40];
	struct Book *next; // 指向下一个Book结构体
};

int main(void)
{
	return 0;
}
