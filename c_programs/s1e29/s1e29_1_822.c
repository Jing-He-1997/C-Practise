#include <stdio.h>

#define MAX 64

char *myitoa(int num, char *str);

char *myitoa(int num, char *str)
{
	int i = 0, temp;
	
	if(num < 0)
	{
		num = (-1)*num;
		str[i++] = '-';
	}

	int len = 0, k;
	k = num;
	while(k)
	{
		k = k /10;
		len++;
	}	

	//520, 20 
	while(len--)
	{
		temp = num;
		int count = 1;
		//520 52 5, 20
		while(temp > 10)
		{
			//52 5, 2
			temp = temp/10;
			//10 100, 10
			count *= 10;
		}
		//5
		str[i++] = temp + '0';
		
		//520-5*100
		num = num - temp*count; 	
	}
	
	str[i] = '\0';

	return str;
}

int main(void)
{
	char str[MAX];

	printf("%s\n", myitoa(520, str));
	printf("%s\n", myitoa(-1234, str));

	return 0;
}
