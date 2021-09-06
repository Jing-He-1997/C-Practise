#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int *ptr1 = NULL;
	int *ptr2 = NULL;

	ptr1 = (int *)malloc(sizeof(int) * 10);

	//ptr1进行若干操作后发现申请的内存不够
	
	ptr2 = (int *)malloc(sizeof(int) * 20);

	//将ptr1指向的内容复制到ptr2中
	//First argument is where the contents need to be copied to
	//Second argument is the original address of the contents
	//Third argument is the copy length
	memcpy(ptr2, ptr1, sizeof(int) * 10);

	free(ptr1);

	//ptr2进行若干操作...
	
	free(ptr2);
	return 0;
}
