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

void getInput(struct Book *book);
void printBook(struct Book *book);

int main(void)
{
	struct Book *book = NULL;
	int flag = 1;
	int i;
	int bookNum = 1;

	printf("\n======欢迎来到图书馆系统======\n\n");

	while(flag)
	{
		book = (struct Book *)realloc(book, bookNum * sizeof(struct Book));
	
		if(book == NULL)
		{
			printf("动态内存分配失败！\n");
			exit(1);
		}

		getInput(book + (bookNum-1));
		bookNum++;
		printf("书籍输入完毕，是否继续输入?(1/0):");
		scanf("%d", &flag);
		putchar('\n');
	}

	printf("=======录入完毕=======\n\n");

	for(i = 0; i < bookNum-1; i++)
	{
		printf("第%d本书: \n", i+1);
		printBook(book+i);
	}

	return 0;
}

void getInput(struct Book *book)
{
	printf("请输入书名:");
	scanf("%s", book->title);
	printf("请输入作者:");
	scanf("%s", book->author);
	printf("请输入价格:");
	scanf("%f", &book->price);
	printf("请输入日期(YY-MM-DD):");
	scanf("%d-%d-%d", &book->date.year, &book->date.month, &book->date.day);
	printf("请输入出版社:");
	scanf("%s", book->publisher);
}

void printBook(struct Book *book)
{
	printf("书名:\t%s\n", book->title);
	printf("作者:\t%s\n", book->author);
	printf("价格:\t%.2f\n", book->price);
	printf("日期:\t%d-%d-%d\n", book->date.year, book->date.month, book->date.day);
	printf("出版社:\t%s\n", book->publisher);
}
