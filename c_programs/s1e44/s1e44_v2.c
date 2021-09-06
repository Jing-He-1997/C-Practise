#include <stdio.h>

struct Book getInput(struct Book book);
void printBook(struct Book book);

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
};

struct Book getInput(struct Book book)
{
	printf("请输入书名：");
	scanf("%s", book.title);
	printf("请输入作者：");
	scanf("%s", book.author);
	printf("请输入价格：");
	scanf("%f", &book.price);
	printf("请输入日期(YY-MM-DD)：");
	scanf("%d-%d-%d", &book.date.year, &book.date.month, &book.date.day);
	printf("请输入出版社：");
	scanf("%s", book.publisher);

	return book;	
}

void printBook(struct Book book)
{
	printf("书名:%s\n", book.title);
	printf("作者:%s\n", book.author);
	printf("售价:%.2f\n", book.price);
	printf("出版日期:%d-%02d-%02d\n", book.date.year, book.date.month, book.date.day);
	printf("出版社:%s\n", book.publisher);
}

int main(void)
{
	struct Book b1, b2;
	printf("请输入第1本书的信息...\n");
	b1 = getInput(b1);
	putchar('\n');
	printf("请输入第2本书的信息...\n"); 
	b2 = getInput(b2);

	printf("\n\n============录入完毕===============\n\n");

	printf("第1本书的信息：\n");
	printBook(b1);
	printf("\n第2本书的信息：\n");
	printBook(b2);	
		
	return 0;
}
