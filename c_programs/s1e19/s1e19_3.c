#include <stdio.h>
#include <string.h>

#define NUM 128
int main()
{
	char str[NUM];
	char str1[NUM];
	_Bool flag = 1;
	int k = 0;
	int temp;
	printf("请输入英文文本：");
	scanf("%[^\n]",&str);

	for(int i = 0; i<strlen(str);i++)
	{
		flag = 1;
		for(int j = 0; j<= i; j++)
		{
			if(str1[j]== str[i])//判断有无重复
			{
				flag = 0;
				break;
			}
		}
		if(flag)//无重复的话就复制进str1
		{
			str1[k] = str[i];
			k++;
		}
	}
	str1[k]='\0'; //字符串最后输入一个0终止符

	printf("你总共输入了%d个字符，其中不同的字符个数有%d个\n",strlen(str),strlen(str1));
	printf("它们是：%s\n",str1);

	int a[strlen(str1)];
	k = 0;//将k重置
	int res = 0, l = 0;//res用来存放最多出现次数，l用来存放最多次出现的字符的位置
	for(int num = 0; num < strlen(str1); num++)
	{
		a[k]= 0;
		for(int num1 = 0; num1<strlen(str);num1++)
		{
			if(str1[num]== str[num1])
			{
				a[k]++;
			}
		}
		if(res < a[k])
		{
			res = a[k];
			 l  = k;
		}
		k++;
	}
	
	printf("出现次数最多的字符是\'%c\'，它总共出现了%d次\n",str1[l],res);
	return 0;
}
