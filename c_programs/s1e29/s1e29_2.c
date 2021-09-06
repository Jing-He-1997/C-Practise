#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//myprintf函数是实现printf的功能
int myprintf(char *str, ...);
//countInt函数计算出整型数字转换成字符后的个数
int countInt(int num);
//打印（后转换成字符型）整型数字
void printInt(int num);
//打印字符串
void printStr(char *str);

void printInt(int num)
{
	int dec = 1;
	int temp;

	if(num < 0)
	{
		putchar('-');
		num = -num;
	}
	temp = num;

	while(temp > 9)
	{
		dec*= 10;
		temp /= 10;
	}

	while(dec!= 0)
	{
		putchar(num / dec + '0');
		num = num % dec;
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

	do
	{
		count++;
	}while(num /= 10);

	return count;
}

void printStr(char *str)
{
	int i = 0;
	while(str[i]!= '\0')
	{
		putchar(str[i]);
		i++;
	}
}

int myprintf(char *str, ...)
{
	int i = 0;
	int count = 0;
	int darg;
	char carg;
	char *sarg;

	va_list vap;
	va_start(vap, str);

	while(str[i]!= '\0')
	{	if(str[i]!='%')
		{
			putchar(str[i]);
			i++;
			count++;
		}
		else
		{
			switch(str[i+1])
			{
				case 'd': 
				{
					darg = va_arg(vap, int);
					printInt(darg);
					count += countInt(darg);
					break;
				}
				case 'c': 
				{	
					carg = va_arg(vap, int);
					putchar(carg);
					count++;
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
			i += 2;
		}
	}
	va_end(vap);

	return count;	
}
int main()
{
	int i;
	
	i = myprintf("Hello %s\n", "FishC");
	myprintf("共打印了%d个字符(包括\\n)\n", i);
	i = myprintf("int: %d, char: %c\n", -520, 'H');
	myprintf("共打印了%d个字符(包括\\n)\n", i);

	return 0;
}
