#include <stdio.h>

int main(void)
{
	struct Date
	{
		int year;
		int month;
		int day;
	};

	struct Book
	{
		char title[128]; 	/* 128 bytes */
		char author[40]; 	/* 40 bytes (total 168 bytes)*/
		float price;		/* 4 bytes (total 172 bytes)*/
		struct Date date;	/* 12 bytes (total 184 bytes)*/
		char publisher[40];	/* 40 bytes (total 224 bytes)*/
	};

	struct Book book;

	printf("size of book = %d\n", sizeof(book));
	return 0;
}
