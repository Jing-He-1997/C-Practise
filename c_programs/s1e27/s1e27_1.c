#include <stdio.h>

int main(void)
{
	int a = 0x12345678;
	unsigned char *b = (unsigned char *)&a;

	if(*b == 0x12)
	{
		printf("您的机器采用大端节序！\n");
	}
	else
	{
		printf("您的机器采用小端节序！\n");
	}
	
	printf("0x%x在内存中依次存放为:", a);
	int len = sizeof(int);
	while(len--)
	{
		printf("0x%x ",*b++);	
	}
	
	printf("\n");
	
	return 0;
}
