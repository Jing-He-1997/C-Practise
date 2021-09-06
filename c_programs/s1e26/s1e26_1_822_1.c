#include <stdio.h>

#define MAX 1024
int main(void)
{
	char str[MAX];
	char *p = str;
	char *pos[MAX] = {0};
	int i = 0, max = 0, j = 0;
	int cChar = 0, cWord = 0;

	printf("请输入一个英文句子:");
	
	//将输入的字符串存入str中
	while((str[i++] = getchar())!= '\n' && i+1 < MAX)
		; //循环结束时str[i-1] = '\n'

	str[i-1] = '\0';

	if(*p != ' ')
	{
		pos[j++] = p;
		cWord++;
	}
	while(i--)
	{
		if(*p++ == ' ')
		{
			//这里面的指针p指向的地址时if括号号中指针p指向的地址的下一个地址
			max = max > cChar ? max : cChar;
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

	max = max > --cChar? max : cChar;

	char result[cWord][max+1];

	for(i = 0; i < cWord; i++)
	{
		//pos中存放的是每个单词的首地址，它们的结尾一定是' '或者'\0'
		for(j = 0; *(pos[i]+j) != ' ' && *(pos[i]+j) != '\0'; j++)
		{
			result[i][j] = *(pos[i]+j);
		}
		result[i][j] = '\0';
	}

	printf("分割结果已存放在result[%d][%d]的二维数组中...\n", cWord, max+1);
	printf("现在依次打印每个单词:\n");
	
	for(i = 0; i < cWord; i++)
	{
		printf("%s\n", result[i]);
	}
	return 0;
}
