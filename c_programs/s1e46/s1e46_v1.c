#include <stdio.h>
#include <stdlib.h>

struct Book
{
	char title[128];
	char author[40];
	float price;
	char publisher[40];
	struct Book *next;
};

void getInput(struct Book *book);
void printLibrary(struct Book *library);
void releaseLibrary(struct Book **library);
void addBook(struct Book **library);

void getInput(struct Book *book)
{
	printf("请输入书名:");
	scanf("%s", book -> title);
	printf("请输入作者:");
	scanf("%s", book -> author);
	printf("请输入售价:");
	scanf("%f", &book -> price);
	printf("请输入出版社:");
	scanf("%s", book -> publisher);
}

void printLibrary(struct Book *library)
{
	struct Book *book;
	int count = 1;
	book = library;
	
	while(book != NULL)
	{
		printf("Book%d:\n", count);
		printf("Book title: %s\n", book->title);
		printf("Book author: %s\n", book->author);
		printf("Book price: %.2f\n", book->price);
		printf("Book publisher: %s\n", book->publisher);
		book = book->next; 	// 打印完成后，需要将book指向下一个节点
					//否则，会出现死循环！
		count++;		
	}
}

void releaseLibrary(struct Book **library)
{
	struct Book *temp;
	while(*library != NULL)
	{
		temp = *library;
		
		*library = (*library)->next;
		free(temp);
	}
}

//两个解引用的原因：因为在单链表中插入节点时，需要修改的是链表头部的指针(struct Book *library);
//所以，需要将链表头部指针的地址传入函数中;
//如果是void addBook(struct Book *library),则library指针(链表头部指针)无法在main函数中修改;
void addBook(struct Book **library)
{
	struct Book *book, *temp;
	book = (struct Book *)malloc(sizeof(struct Book));
	
	if(book == NULL)
	{
		printf("动态内存分配失败！\n");
		exit(1);
	}

	getInput(book);

	if(*library != NULL)
	{
		temp = *library;
		//定位到单链表的最后一位
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = book;
		book->next = NULL;
	}
	else
	{
		*library = book;
		book->next = NULL;
	}
}

int main(void)
{
	struct Book *library = NULL;
	int ch;

	while(1)
	{
		printf("请问是否需要录入书籍信息(Y/N):");
		do
		{
			ch = getchar();
		}while(ch != 'Y' && ch!= 'N');

		if(ch == 'Y')
		{
			addBook(&library);
		}
		else
		{
			break;
		}
	}

	printf("\n\n请问是否需要打印图书信息(Y/N):");
	do
	{
		ch = getchar();
	}while(ch != 'Y' && ch != 'N');


	if(ch == 'Y')
	{
		printLibrary(library);
	}
	
	releaseLibrary(&library);
	return 0;
}
