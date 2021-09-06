#include <stdio.h>
#include <string.h>

int main()
{
	char *pArray[4] = {
		"Hello",
		"How are you?",
		"Fine, thank you. And you?",
		"I'm fine too."
	};

	char *(*p)[4] = &pArray;

	int i, j;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < strlen(*(*p+i)); j++)
		{
			printf("%c ",*(*(*p + i)+j));
		}
		printf("\n");
	}


	// p 指向的是整个指针数组的地址，p的跨度为 0x20h
	// *p指向的是指针数组中第一个字符串的地址，*p的跨度 0x08h
	// **p指向的是指针数组中第一个字符串的第一个字符的地址, **p的跨度为0x01h
	// ***p是指针数组中第一个字符串的第一个字符的值
	printf("p: %p, p+1: %p\n", p, p+1);
	printf("*p: %p,*p+1: %p\n", *p, *p+1);
	printf("**p: %p, **p + 1: %p\n", **p, **p+1);
	printf("***p: %c, ***p+1: %c\n", ***p, ***p+1);
	
	return 0;
}
