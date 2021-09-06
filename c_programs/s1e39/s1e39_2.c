#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 10
#define INIT_SIZE INCREMENT

char *get_str(void);
char *reverse_str(char *str);

char *get_str(void)
{
	char *str;
	char *last;
	char ch;
	int limit = 0;
	int times = 1;

	str = (char *)malloc(INIT_SIZE);
	last = str;

	printf("请输入一个字符串：");
	while((ch = getchar()) != '\n')
	{
		last[limit++] = ch;
		if(limit >= INCREMENT)
		{
			int offset = last - str;
			str = (char *)realloc(str, INIT_SIZE + INCREMENT*times++);
			last = str;
			last += offset;
			last += INCREMENT;
			limit = 0;
			
		}
	last[limit] = '\0';
	}

	return str;
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
		str -= 2;	// 将指针指向字符串的最后一个字符
				// str-1是 '\0'所在的地址!!!

		while(left < str)
		{
			ch = *left;	//1. 将字符串前面的字符先放入ch中；
			*left++ = *str;	//2. 将字符串后面的字符放入字符串的前面，
					//   完成后将left指针向后移动一个单位；
			*str-- = ch;	//3. 将存放在ch中的字符放入字符串后面，
		}
	}

	return start;
}

int main(void)
{
	char *str = NULL;

	str = get_str();
	str = reverse_str(str);

	printf("前后翻转的结果：%s\n", str);
	free(str);
	return 0;
}
