#include <stdio.h>
#include <string.h>

#define NUM 128

int main()
{
	int ch, i, j = 0, max = 0;
	int input_num = 0;
	int ascii[NUM]={0};
	char count[NUM]= "";

	printf("请输入英文文本：");
	
	while((ch = getchar())!='\n')
	{
		ascii[ch]++; //字符对应的ascii码+ 1
		input_num++;//记录输入了多少个字符
	}
	
	for(i = 0; i < NUM; i++)//间接的将打印出来的字符排了序
	{
		if(ascii[i])
		{
			count[j++] = i;//每个count[]存放的是不同字符
			if(ascii[i]> ascii[max])
			{
				max = i;//max的值代表出现次数最多的字符
			}
		}
	}
	printf("你总共输入了%d个字符，其中不同的字符个数有%d个。\n", input_num,strlen(count));
	printf("它们是：%s\n",count);
	printf("出现次数最多的字符是\'%c\',它总共出现了%d次。\n",max, ascii[max]);

	return 0;
}
