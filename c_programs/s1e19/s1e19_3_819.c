#include <stdio.h>
#include <string.h>

#define MAX 128

int main(void)
{
	int ch, i, j = 0, count1 = 0, count2 = 0;
	int max = 0;
	
	int ascii[MAX] = {0};
	int res[MAX] = {0};
	
	printf("请输入英文文本:");
	while((ch = getchar()) != '\n')
	{
		ascii[ch]++;
		count1++;
	}
	printf("你总共输入了%d个字符!\n", count1);
	printf("它们是:");
	for(i = 0; i < MAX; i++)
	{
		if(ascii[i] != 0)
		{
			printf("%c", i);
			count2++;
			max = (max > ascii[i])? max : ascii[i];
		}
	}

	for(i = 0; i < MAX; i++)
	{
		if(ascii[i] == max)
		{
			res[j] = i;
			j++;
		}
	}
	putchar('\n');
	printf("其中不同的字符个数有%d个!\n", count2);

	printf("出现次数最多的字符是");
	for(i = 0; i < j; i++)
	{
		printf("\'%c\' ", res[i]);
	}
	printf(", 它(们)总共出现了%d次!\n", max);
	return 0;
}
