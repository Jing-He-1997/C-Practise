#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int myprintf(char *format, ...);
int countInt(int num);
void printInt(int num);
void printStr(char *str);

//递归的方法
void printInt(int num)
{
	int temp;

	if(num < 0)
	{
		putchar('-');
		num = -num;
	}

	temp = num;
	num = num / 10;
	if(temp != 0)
	{
		printInt(num);
		putchar(temp%10 + '0');
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

	while(str[i] != 0)
	{
		putchar(str[i]);
		i++;
	}
}

int myprintf(char *format, ...)
{
	int i = 0;
	int count = 0;
	int darg;
	char carg;
	char *sarg;
	va_list vap;

	va_start(vap, format);

	while(format[i] != '\0')
	{
		//如果不是格式化占位符，直接打印字符串
		if(format[i] != '%')
		{
			putchar(format[i]);
			i++;
			count++;
		}
		//如果是格式化字符
		else
		{
			switch(format[i+1])
			{
				case 'c':
					{
						carg = va_arg(vap, int);
						putchar(carg);
						count++;
						break;
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
						sarg = va_arg(vap, char *);
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

int main(void)
{
	int i;

	i = myprintf("Hello %s\n", "JINGG");
	myprintf("共打印了%d个字符(包含\\n)\n", i);
	i = myprintf("int: %d, char: %c\n", -520, 'H');
	myprintf("共打印了%d个字符(包含\\n)\n", i);
	
	return 0;
}

