#include <stdio.h>

#define ARGUMENTS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, ...) A11
#define COUNTS(...) ARGUMENTS(FISHC, ## __VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

//第一个__VA_ARGS__是%s(字符串)，打印后在COUNTS()的'()'中
//第二个__VA_ARGS__是COUNTS(...)中替换的内容
#define PRINT_COUNTS(...) printf("COUNTS(%s)有%d个参数\n", #__VA_ARGS__, COUNTS(__VA_ARGS__))

int main(void)
{

	PRINT_COUNTS();
//下面式子将被替换成
//printf("COUNTS(%s)有%d个参数\n", "1, 2, 3", ARGUMENTS(FISHC,1,2,3,9,8,7,6,5,4,3,2,1,0));
	PRINT_COUNTS(1, 2, 3);
	PRINT_COUNTS("Apple", "Banana", "Cat", "Dog");
	return 0;
}
