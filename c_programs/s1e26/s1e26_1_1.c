#include <stdio.h>

#define MAX 1024
int main()
{
	char str[MAX];
	char *p = str;//间接寻址
	char *pos[MAX] = {0}; //记录每个单词的地址

	int len = 0;
	int cChar = 0, cWord = 0; //cChar统计字符数，cWord统计单词数
	int max = 0, i = 0, j;

	printf("请输入一个英文句子：");
	
	//接受输入
	while((str[len++] = getchar())!= '\n' && len + 1 < 1024)
		;

	str[len - 1] = '\0';
	
	if(*p != ' ')
	{
		pos[i++] = p; //记录第一个单词的地址
		cWord++;
	}

	while(len--)
	{
		
		if(*p++ == ' ')//在这里就p++了
		{
			//判断最大字符数
			max = cChar > max? cChar:max;
			cChar = 0;
		
			//退出循环
			if(*p == '\0')
			{
			break;
			}
			//单词数+1
			if(*p != ' ')
			{
				pos[i++] = p;
				cWord++;
			}
		}
		else//这样就不会把空格统计进去了
		{
			cChar++;
		}
	}
	max = --cChar > max? cChar : max;//最后会算多一个'\0',所以减去

	char result[cWord][max+1];//+1是为了存放'\0'
	
	//将分割好的单词放入二维数组中！！
	for(i = 0; i < cWord; i++)
	{
		for(j = 0; *(pos[i] + j)!=' ' && *(pos[i]+j)!= '\0'; j++)
		{
			result[i][j] = *(pos[i]+j);
		}
		result[i][j] = '\0';
	}

	printf("分割结果已经存放到result[%d][%d]的二维数组中..\n", cWord, max+1);
	printf("现在依次打印每个单词：\n");
	for(i = 0; i < cWord; i++)
	{
		printf("%s\n", result[i]);
	}
	
	return 0;
}
