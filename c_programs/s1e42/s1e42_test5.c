#include <stdio.h>

int main(void)
{
	//利用位域(bitfields)，能声明比字符宽度更小的成员
	struct Test
	{
		short s; 	/* 2 bytes */
		char c; 	/* 1 byte  */
		int filp:6; 	/* total 1 bit */ 
		int nybble:4;	/* total 5 bits */
		int septet:7;	/* total 12 bits (aligned with 16bits)*/
		//因为是x64，所以sizeof(test) == 8
	} test;

	
	printf("size of test = %d\n", sizeof(test));
	return 0;
}
