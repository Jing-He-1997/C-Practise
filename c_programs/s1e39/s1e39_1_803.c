#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 10
#define INIT_SIZE INCREMENT
int main(void)
{
	char ch;
	char *num;
	char *last;
	int limit = 0;
	long times = 1;
	
	num = (char *)malloc(INIT_SIZE);
	
	if(num == NULL)
	{
		printf("动态内存分配失败！\n");
		exit(1);
	}
	last = num;

	printf("请输入一个整数：");

	while((ch = getchar()) != '\n')
	{
		last[limit++] = ch;

		if(limit >= INCREMENT)
		{
			int offset = last - num;
			num = (char *) realloc(num, INIT_SIZE + INCREMENT * times++);
			last = num;
			last += offset;
			last += INCREMENT;
			limit = 0;
		}
	}
	last[limit] = '\0';

	printf("你输入的整数是：%s\n", num);

	return 0;
}
