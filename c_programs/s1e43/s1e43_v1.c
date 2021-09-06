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

	printf("\n==============录入数据完毕！=============\n\n");
	printf("书名：%s\n", book.title);
	printf("作者：%s\n", book.author);
	printf("售价：%.2f\n", book.price);
	printf("出版日期：%d-%02d-%02d\n",book.date.year, book.date.month, book.date.day);
	printf("出版社：%s\n\n", book.publisher);	

	return 0;
}
