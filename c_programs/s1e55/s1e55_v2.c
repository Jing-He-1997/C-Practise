#include <stdio.h>

int main(void)
{
	char i = 0x40;			//0x40的二进制为01000000
	unsigned char j = 0x40;		

	i <<= 1;
	j <<= 1;

	printf("i = 0x%X, j = 0x%X\n",i , j);
	return 0;
}
