#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr1 = NULL;
	int *ptr2 = NULL;//ptr1和ptr2是局部变量，它们的地址被系统申请在栈中；

	ptr1 = (int *)malloc(sizeof(int));
	ptr2 = (int *)malloc(sizeof(int));

	printf("stack: %p -> %p\n", &ptr1, &ptr2);
	printf("heap: %p -> %p\n", ptr1, ptr2);
	ptr1 = (int *)realloc(ptr1, 20* sizeof(int));

	printf("heap after realloc: %p -> %p\n", ptr1, ptr2);

	free(ptr1);
	free(ptr2);
	return 0;
}
