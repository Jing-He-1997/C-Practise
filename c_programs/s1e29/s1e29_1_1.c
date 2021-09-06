#include <stdio.h>

char* myitoa(int n, char* str);

char* myitoa(int n, char* str)
{
	int i = 0, temp; 
	int dec = 1, count = 1;//因为求余时个位数也需要算进去，所以count得从1开始
	if(n < 0)
	{
		str[i++] = '-';
		n = -n;
	}

	temp = n;

	do
	{
		dec *= 10;
		temp /= 10;
		count++;
	}while(temp > 10);

//	printf("temp = %d\n",temp);

	while(count--)
	{
		str[i++] = n / dec + '0';
		n = n % dec;
		dec /= 10;
	}
	str[i] = '\0';

	return str;	
}
int main()
{
	char str[10];
	
	printf("%s\n",myitoa(520, str));
	printf("%s\n",myitoa(-1234, str));

	return 0;
}
