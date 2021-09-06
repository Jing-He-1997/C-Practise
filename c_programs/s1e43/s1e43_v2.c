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
} book;

int main(void)
{
	printf("请输入书名：");
	scanf("%s", book.title);
	printf("请输入作者：");
	scanf("%s", book.author);
	printf("请输入售价：");
	scanf("%f", &book.price);
	printf("请输入出版日期：");
	scanf("%d-%d-%d", &book.date.year, &book.date.month, &book.date.day);
	printf("请输入出版社：");
	scanf("%s", book.publisher);

	struct Book *pt; //声明一个结构体指针
	pt = &book;

	printf("\n==============录入数据完毕！=============\n\n");
	printf("书名：%s\n", (*pt).title);
	printf("作者：%s\n", (*pt).author);
	printf("售价：%.2f\n", (*pt).price);
	printf("出版日期：%d-%02d-%02d\n",(*pt).date.year, (*pt).date.month, (*pt).date.day);
	printf("出版社：%s\n\n", (*pt).publisher);	

	return 0;
}
