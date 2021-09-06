#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 10
#define INIT_SIZE INCREMENT
int main(void)
{
	char ch;
	char *num;//存储整个数据的首地址
	char *last;// 最近一次迭代的起始地址
	int limit = 0;//每次迭代的限制值
	long times = 1;//记录重新申请了多少次内存

	num = (char *)malloc(INIT_SIZE);
	if(num == NULL)
	{
		printf("申请动态内存失败！\n");
		exit(1);
	}

	last = num;

	printf("addr of num : %p\n", num);

	printf("请输入一个整数：");
	
	while((ch = getchar())!='\n')
	{
		last[limit++] = ch;
		if(limit >= INCREMENT)
		{
			int offset = last - num;//在第一次时，offset的值为0
						//因为最开始last和num指针指向的首地址是一样的
			printf("offset = %d\n", offset);
			printf("addr of num: %p\n", num);
			printf("addr of last: %p\n", last);
			num = (char *)realloc(num, INIT_SIZE + INCREMENT * times++);
			last = num;
			last += offset;
			last += INCREMENT;//移动last指针指向的地址
			limit = 0;
			printf("after realloc, offset = %d\n", offset);
			printf("after realloc, addr of num: %p\n", num);
			printf("after realloc , addr of last: %p\n", last);
		}
	}

	last[limit] = '\0';

	printf("您输入的整数是：%s\n", num);
	printf("重新申请了%d次内存\n", times);
	free(num);	
	return 0;
}
