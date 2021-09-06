#include <stdio.h>

inline int square(int x);

inline int square(int x)
{
	return x * x;
}
int main(void)
{
	int i = 1;

	while(i <= 100)
	{
		//实参是从右边开始入栈
		printf("%d的平方为%d\n", i-1, square(i++));
	}
	return 0;
}
