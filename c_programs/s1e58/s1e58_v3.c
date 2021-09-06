#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
	int year;
	int month;
	int day;
};

typedef struct Book
{
	char name[40];
	char author[20];
	char publisher[40];
	struct Date date;
} BOOK, *PTRBOOK;

int main(void)
{
	PTRBOOK book_for_write, book_for_read;
	FILE *fp;

	book_for_write = (PTRBOOK)malloc(sizeof(BOOK));
	book_for_read = (PTRBOOK)malloc(sizeof(BOOK));

	if(book_for_write == NULL || book_for_read == NULL)
	{
		printf("动态内存分配失败!\n");
		exit(1);	
	}

	strcpy(book_for_write->name, "<Slam Dunk>");
	strcpy(book_for_write->author, "井上雄彦");
	strcpy(book_for_write->publisher, "JUMP");
	book_for_write->date.year = 1990;
	book_for_write->date.month = 8;
	book_for_write->date.day = 26;
	
	if((fp = fopen("file_book.txt", "w")) == NULL)	
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}

	fwrite(book_for_write, sizeof(BOOK), 1, fp);

	fclose(fp);

	if((fp = fopen("file_book.txt", "r")) == NULL)	
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}
	
	fread(book_for_read, sizeof(BOOK), 1, fp);
	printf("书名:%s\n", book_for_read->name);
	printf("作者:%s\n", book_for_read->author);
	printf("出版社:%s\n", book_for_read->publisher);
	printf("出版日期:%d-%d-%d\n", book_for_read->date.year, book_for_read->date.month, book_for_read->date.day);

	fclose(fp);
	return 0;
}
