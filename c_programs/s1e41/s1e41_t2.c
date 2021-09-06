#include <stdio.h>

#define PRINT(format, ...) printf(# format, __VA_ARGS__)

int main(void)
{
	PRINT(num = %d\n, 520);
	//不加##的话， 这一句无法执行
//	PRINT(Hello JING HE!\n);

	return 0;
}
