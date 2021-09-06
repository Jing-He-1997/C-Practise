#include <stdio.h>

#define MAX 1024
int main(void)
{
	int i = 0, j = 0;
	char str[MAX];
	char *p = str;
	char *pos[MAX] = {0};
	int cWord = 0, cChar = 0;
	int max = 0;

	printf("请输入一个英文句子:");
	
	//所有输入的内容存放到str中
	while((str[i++] = getchar()) != '\n' && i + 1 < MAX)
		;

	str[i - 1] = '\0'; //str[i-1] 原来是存放'\n'

	//当指针走到不是空格的位置时，cWord立马+1
	if(*p != ' ')
	{
		pos[j++] = p; //记录第一个单词的地址
		cWord++;
	}

	while(i--)
	{			//aa  a  aa a aa
				//if条件语句判断时,指针p依然处在当前位置;
		if(*p++ == ' ')	//if条件语句判断的这一行指令结束并进入max...后, 指针p已经指向下
				//一个位置。
				//不管判断的条件是真是假,++都会在条件语句执行后生效
		{
			max = max > cChar? max:cChar;
			cChar = 0;

			if(*p == '\0')
			{
				break;
			}

			if(*p != ' ')
			{
				pos[j++] = p;
				cWord++;
			}
		}
		else
		{
			cChar++;
		}	
	}

	//最后一段字符输入结束后，如果后面没有跟空格，那么需要再次判断一下最大字符数是否有变化
	//因为最后一段字符带有一个'\0'，所以在判断时需要将其减去
	max = max > --cChar? max : cChar;

	char result[cWord][max+1];

	//将pos中的分好的单词放进二维数组中
	for(i = 0; i < cWord; i++)
	{
		for(j = 0; *(pos[i]+j) != ' ' && *(pos[i]+j) != '\0'; j++)
		{
			result[i][j] = *(pos[i]+j);
		}
		result[i][j] = '\0';
	}

	printf("分割结果已经存放到[%d][%d]的二维数组中...\n", cWord, max+1);
	printf("现在依次打包每个单词:\n");
	for(i = 0; i < cWord; i++)
	{
		printf("%s\n", result[i]);
	}

	return 0;
}

