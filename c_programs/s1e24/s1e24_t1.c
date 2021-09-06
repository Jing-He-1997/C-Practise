#include <stdio.h>

int main()
{
	char matrix[3][5]={
		'I', 'l', 'o', 'v', 'e',
		'F', 'i', 's', 'h', 'c',
		'.', 'c', 'o', 'm', '!'
	};

	char *p;

	p = &matrix[0][3];

	printf("%c", *p);
	printf("%c", *p++);
	printf("%c", *++p);
	printf("\n");

	printf("%s\n", *(matrix + 1)+ 2);
	return 0;
}
