#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *use_malloc(int n)
{
	char *array;

	array = (char *)malloc(n);
	strcpy(array, "Hejing zhendebang");

	return array;
}

char *use_VLA(int n)//VLA（变长数组）是局部变量，所以是存放在栈上
{
	char array[n];
	strcpy(array, "Hejing zhendebang");

	return array;
}

int main(void)
{
	printf("use_malloc: %s\n", use_malloc(18));
	printf("use_VLA: %s\n", use_VLA(18));

	return 0;
}
