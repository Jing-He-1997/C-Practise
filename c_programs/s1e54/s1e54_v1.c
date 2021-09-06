#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("一个字节是 %d 位!\n", CHAR_BIT);

	printf("signed char的最小值是 %d\n", SCHAR_MIN);
	printf("signed char的最大值是 %d\n", SCHAR_MAX);
	printf("unsigned char的最大值是 %u\n", UCHAR_MAX);

	printf("signed short的最小值是 %d\n", SHRT_MIN);
	printf("signed short的最大值是 %d\n", SHRT_MAX);
	printf("unsigned short的最大值是 %u\n", USHRT_MAX);

	printf("signed int的最小值是 %d\n", INT_MIN);
	printf("signed int的最大值是 %d\n", INT_MAX);
	printf("unsigned int的最大值是 %u\n", UINT_MAX);
	
	printf("signed long的最小值是 %ld\n",LONG_MIN);
	printf("signed long的最大值是 %ld\n",LONG_MAX);
	printf("signed long的最大值是 %lu\n",ULONG_MAX);

	printf("signed long long的最小值是 %lld\n", LLONG_MIN);
	printf("signed long long的最大值是 %lld\n", LLONG_MAX);
	printf("signed long long的最大值是 %llu\n", ULLONG_MAX);
	
	return 0;
}
