#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 10
#define INIT_SIZE INCREMENT

char *get_num(void);
char *reverse_num(char *num);
char *append_result(char *result, char ch);
char *add_nums(char *num1, char *num2);

char *get_num(void)
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
	while((ch = getchar())!= '\n')
	{
		last[limit++] = ch;
		if(limit >= INCREMENT)
		{
			int offset = last - num;
			num = (char *)realloc(num, INIT_SIZE + INCREMENT * times++);
			last = num;
			last += offset;
			last += INCREMENT;
			limit = 0;
		}
	}

	last[limit] = '\0';

	return num;	
}

char *reverse_num(char *num)
{
	char ch;
	char *start = num;
	char *left = num;

	if(num != NULL)
	{
		while(*num++)
			;
		num -= 2;

		while(left < num)
		{
			ch = *left;
			*left++ = *num;
			*num-- = ch;
		}
	}

	return start;
}

char *append_result(char *result, char ch)
{
	char *last;
	int limit = 0;
	long times = 1;

	last = result;
	
	//将指针指向末尾'\0'处
	while(last[limit++] != '\0')
	{
		if(limit >= INCREMENT)
		{
			last += INCREMENT;
			times++;
			limit = 0;
		}	
	}

	last[limit-1] = ch;

	if(limit >= INCREMENT)
	{
		int offset = last - result;
		result = (char *)realloc(result,INIT_SIZE + INCREMENT*times);
		last = result;
		last += offset;
		last += INCREMENT;
		limit = 0;
	}

	last[limit] = '\0';
	
	return result;
}

char *add_nums(char *num1, char *num2)
{
	int carry = 0;
	int n1, n2, n3;
	char *res;

	//先为res在堆上分配一个的空间
	res = (char *)malloc(INIT_SIZE);
	if(res == NULL)
	{
		printf("动态内存分配失败！\n");
		exit(1);
	}
	
	//reverse_num后res[0]就到最后面了
	res[0] = '\0';

	//翻转num1，num2
	num1 = reverse_num(num1);
	num2 = reverse_num(num2);

	while(*num1 != '\0' || *num2 != '\0')
	{
		n1 = *num1 - '0';
		n2 = *num2 - '0';

		if(*num1 == '\0')
		{
			n1 = 0;
		}
		else
		{
			num1++;
		}

		if(*num2 == '\0')
		{
			n2 = 0;
		}
		else
		{
			num2++;
		}

		n3 = n1+n2+carry;

		if(n3 > 9)
		{
			res = append_result(res, n3 - 10 + '0');
			carry = 1;
		}
		else
		{
			res = append_result(res, n3 + '0');
			carry = 0;
		}
	}

	//最后，如果carry仍然等于1，那么需要把它打印出来
	if(carry)
	{
		append_result(res, carry + '0');
	}

	res = reverse_num(res);

	return res;	
}

int main(void)
{
	char *num1;
	char *num2;
	char *res;

	num1 = get_num();
	num2 = get_num();

	res = add_nums(num1, num2);
	printf("计算结果是: %s\n", res);
	return 0;
}
