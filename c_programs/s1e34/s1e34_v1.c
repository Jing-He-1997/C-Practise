#include <stdio.h>

void recursion(void);


void recursion(void)
{
	static int count = 10;
	printf("Hi!\n");
	
	if(count--)
	{
		recursion(); //必须要设置关闭条件，否则程序会发生段错误！！
	}
}
int main()
{
	recursion();
	
	return 0;	
}
