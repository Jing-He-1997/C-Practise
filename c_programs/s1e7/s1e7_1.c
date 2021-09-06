#include <stdio.h>

int main()
{
	char i;
	unsigned char j;

	i = 255;
	j = 255;

	//1. %d与%hhd的区别：
	//%d把输出解释成一个有符号的十进制整数，%hhd把整数读作signed char或者unsigned char
	//2. %c与%hhd的区别：
	//%c输出时是按照字符操作的，而%hhd输出时是按照整数操作的
	//【同样输出值为48('0'), %c输出为0, %hhd输出为48】
	printf("i的值为%hhd\nj的值为%hhu\n",i,j);
	return 0;
}
