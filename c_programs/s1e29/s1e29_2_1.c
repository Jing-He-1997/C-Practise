#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void printInt(int num);//用来将整型变量转换成字符串并且打印出来
void printStr(char *str);//用来打印字符串
int countInt(int num);//用来计算整型变量转换成字符串后的长度
int myprintf(char *str, ...);//实现printf的功能

void printInt(int num)
{
	int temp, dec = 1;
	if(num < 0)
	{
		putchar('-');
		num = -num;
	}
	temp = num;
	//520 52 5
	while(temp > 9)
	{
		//10 100
		dec *= 10;
		//52 5
		temp /= 10;
	}
	
	while(dec != 0)
	{
		//5 2 0
		putchar(num / dec + '0');
		//20 0 0
		num = num % dec;
		//10 1 0
		dec /= 10;	
	}
}

int countInt(int num)
{
	int count = 0;
	if(num < 0)
	{
		count++;
		num = -num;
	}
	//520
	while(num!=0)
	{
		// 1 2 3
		count++;
		//52 5 0
		num /= 10;
	}
	
	return count;
}

void printStr(char *str)
{
	int i;
	for(i = 0; i < strlen(str); i++)
	{
		putchar(str[i]);
	}
}

int myprintf(char *str, ...)
{
	int i = 0;
	int count = 0;
	int darg;
	int carg;
	char *sarg;
	va_list vap;

	va_start(vap, str);

	//开始打印
	while(str[i]!='\0')
	{
		//当不是占位符的时候
		if(str[i]!='%')
		{
			putchar(str[i++]);
			count++;
		}
		//当是'%'的时候
		else
		{
			//分成c、d、s三种情况
			switch(str[i+1])
			{
				case 'c':
				{
					carg = va_arg(vap, int);
					putchar(carg);
					count++;
					break; //这个忘记了 T T
				}
				case 'd':
				{
					darg = va_arg(vap, int);
					printInt(darg);
					count += countInt(darg);
					break;
				}
				case 's':
				{
					sarg = va_arg(vap, char*);
					printStr(sarg);
					count += strlen(sarg);
					break;
				}
			}
			//跳过%c、%d、%s
			i+= 2;
		}
	}
	va_end(vap);

	return count;
}

int main()
{
	int i;

	i = myprintf("Hello %s\n", "FishC");
	myprintf("共打印了%d个字符(包括\\n)\n",i);
	i = myprintf("int: %d, char: %c\n", -520, 'H');
	myprintf("共打印了%d个字符(包括\\n)\n",i);

	return 0;
}
