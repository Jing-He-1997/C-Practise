#include <stdio.h>
struct Book
{
	char title[128];
	char author[40];
	float price;
	unsigned int date;
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
	scanf("%u", &book.date);
	printf("请输入出版社：");
	scanf("%s", book.publisher);
	printf("\n\n%s\n%s\n%.2f\n%u\n%s\n", book.title, book.author, book.price, book.date, book.publisher);
	
	return 0;
}
