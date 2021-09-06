#include <stdio.h>

#define MAX 1024

int main()
{
	//str存放的是输入的字符
	char str[MAX];

	printf("请输入一个英文句子：");
	fgets(str, MAX, stdin);
	
	// str的指针
	char *p1 = str;
	int length = 0;
	while(*(p1 + length)!= '\0')
	{
		length++;	//得到字符串的长度
	}
	
	int max=0, row=0, count=0;
	int i;

	//计算二维数组一共有多少行，多少列
	for(i = 0; i < length; i++)
	{
		//这里得用&&, 不然当指针指向空格时，右边的比较表达式为真
		if(*(p1 + i)!= ' ' && *(p1 +i)!= '\0')
		{
			count++;
		}

		if(*(p1 + i) == ' ')
		{
			if(*(p1 + i + 1)!= ' ')
			{
				//防止一开头就是空格，所以要先确定前面是否有字符
				if(count != 0)
				{
					max = max > count? max:count;
					row++;
					count = 0;
				}
			}
		}
		//最后一个字符串也要算一行
		if(*(p1 + i + 1)== '\0')
		{
			max = max > count? max:count;
			row++;
			count = 0;
		}
	}

	char result[row][max];
	//二维数组的数组指针	
	char (*p2)[max] = result;
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < max; j++)
		{
			//将str中的空格过滤掉
			while(*p1 == ' ')
			{
				p1++;
			}
			// 将str中的换行符号换成'\0'后退去整个循环
			if(*p1 == '\n')
			{
				*(*(p2 + i)+j) = '\0';
				goto FINISH;
			}
			//将str中的值存储到result中
			else 
			{
				//这里运行完后 p1地址加了1
				*(*(p2 + i)+j) = *(p1++);
				
				//如果加了1后的p1指向空格，那么将result下一个元素赋值为'\0'
				//赋值完后跳出内循环，进入下一行;
				if(*p1 == ' ')
				{
					*(*(p2 + i)+j + 1) = '\0';
					break;
				}
			}
		}
	}

FINISH:
	printf("分割结果已经存放到result[%d][%d]的二维数组中...\n", row, max);
	printf("现在依次打印每个单词：\n");
	for(int i = 0; i < row; i++)
	{
		printf("%s\n", result[i]);
	}		
	return 0;
}
