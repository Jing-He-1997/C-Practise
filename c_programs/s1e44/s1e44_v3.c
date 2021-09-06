#include <stdio.h>
#include <stdlib.h>

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

//得先定义结构体，再使用该结构体
void getInput(struct Book *book);
void printBook(struct Book *book);

void getInput(struct Book *book)
{
	printf("请输入书名：");
	scanf("%s", book->title);
	printf("请输入作者：");
	scanf("%s", book->author);
	printf("请输入价格：");
	scanf("%f", &book->price);
	printf("请输入日期(YY-MM-DD)：");
	scanf("%d-%d-%d", &book->date.year, &book->date.month, &book->date.day);
	printf("请输入出版社：");
	scanf("%s", book->publisher);
}

void printBook(struct Book *book)
{
	printf("书名:%s\n", book->title);
	printf("作者:%s\n", book->author);
	printf("售价:%.2f\n", book->price);
	printf("出版日期:%d-%02d-%02d\n", book->date.year, book->date.month, book->date.day);
	printf("出版社:%s\n", book->publisher);
}

int main(void)
{
	struct Book *b1, *b2;
	b1 = (struct Book *)malloc(sizeof(struct Book));
	b2 = (struct Book *)malloc(sizeof(struct Book));
	if(b1 == NULL || b2 == NULL)
	{
		printf("内存分配失败！\n");
		exit(1);
	}

	printf("请输入第1本书的信息...\n");
	getInput(b1);
	putchar('\n');
	printf("请输入第2本书的信息...\n"); 
	getInput(b2);

	printf("\n\n============录入完毕===============\n\n");
	printf("第1本书的信息：\n");
	printBook(b1);
	printf("\n第2本书的信息：\n");
	printBook(b2);	
	free(b1);
	free(b2);	
	return 0;
}
