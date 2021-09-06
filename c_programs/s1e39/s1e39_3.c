#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENT 10
#define INIT_SIZE INCREMENT

char *get_num(void);
char *reverse_str(char *str);
char *append_result(char *result, char ch);
char *add_str(char *str1, char *str2);

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

	printf("请输入一个整数:");
	
	while((ch = getchar()) != '\n')
	{
		last[limit++] = ch;
		if(limit >= INCREMENT)
		{
			int offset = last - num;
			num = (char *)realloc(num, INIT_SIZE + INCREMENT*times++);
			last = num;
			last += offset;
			last += INCREMENT;
			limit = 0;
		}
	}

	last[limit] = '\0';

	return num;	
}


char *reverse_str(char *str)
{
	char ch;
	char *start = str;
	char *left = str;

	if(str != NULL)
	{
		while(*str++)
			;
		str -= 2;

		while(left < str)
		{
			ch = *left;
			*left++ = *str;
			*str-- = ch;
		}
	}

	return start;
}

char *append_result(char *result, char ch)
{
	char *last = result;
	int limit = 0;
	int times = 1;

	//定位到字符串的末尾
	//while_test.c 可以证明，limit - 2 是字符串最后一个字符的索引位置
	while(last[limit++] != '\0')
	{
		if(limit >= INCREMENT)
		{
			limit = 0;
			times++;
			last += INCREMENT;
		}
	}

	last[limit-1] = ch; //所以limit - 1 是字符串中'\0'的位置，每次调用该函数，把'\0'覆盖掉了

	//如果不够存放了，那就用realloc增加内存
	if(limit >= INCREMENT)
	{
		int offset = last - result;
		result = (char *)realloc(result, INIT_SIZE + INCREMENT * times);
		last = result;
		last += offset;
		last += INCREMENT;
		limit = 0; // reset;
	}

	last[limit] = '\0'; //当limit-1 存放了ch的值了，那么limit位置就需要存放'\0'

	return result;
}

char *add_str(char *str1, char *str2)
{
	int num1, num2, num3;
	int carry = 0;
	char *res;

	res = (char *)malloc(INIT_SIZE);
	if(res == NULL)
	{
		printf("动态内存分配失败！\n");
		exit(1);
	}

	res[0] = '\0';

	//字符串的存放顺序跟加法规则相反
	//需要先反转字符串
	
	str1 = reverse_str(str1);
	str2 = reverse_str(str2);

	//两个字符串按位相加
	while(*str1 != '\0' || *str2 != '\0')
	{
		num1 = *str1 - '0';
		num2 = *str2 - '0';

		if(*str1 == '\0')
		{
			num1 = 0;
		}
		else
		{
			str1++;
		}

		if(*str2 == '\0')
		{
			num2 = 0;
		}
		else
		{
			str2++;
		}

		num3 = num2+num1+carry;

		if(num3 > 9)
		{
			res = append_result(res, num3 - 10 + '0');
			carry = 1;
		}
		else
		{
			res = append_result(res, num3 + '0');
			carry = 0;
		}
	}
	//如果最后有进位没有存放到res中，那么再一次调用append_result函数，将carry放入末位
	if(carry)
	{
		append_result(res, carry + '0');
	}

	//将结果翻转，得到真正的结果！
	res = reverse_str(res);
	return res;
}

int main(void)
{
	char *num1;
	char *num2;
	char *res;

	num1 = get_num();
	num2 = get_num();

	res = add_str(num1, num2);


	printf("res = %s\n", res);

	return 0;
}
