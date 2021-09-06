#include <stdio.h>

//因为返回值是整个数组，所以函数类型的返回值是指针类型
char *myitoa(int num, char *str);

char *myitoa(int num, char *str)
{
	int dec = 1, temp, count = 0;

	if(num < 0)
	{
		str[count++] = '-';
		num = -num;//num小于0时取反
	}
	
	temp = num;
		
	while(temp > 9)
	{
		dec *= 10;//可以得出temp是几位数
		temp /= 10;
	}

	while(dec != 0)
	{
		str[count++] = num / dec + '0';//将数字转换成为ASCII码
		num = num % dec;//去掉最高位数
		dec /= 10;
	}

	str[count] = '\0';//结束后在字符串最后加上'\0'
	return str;
}	


int main()
{
	char str[10];

	printf("%s\n", myitoa(-1234, str));
	printf("%s\n", myitoa(520, str));
	return 0;
}


