#include <stdio.h>

#define PRINT(format, ...) printf(# format, ## __VA_ARGS__)

int main(void)
{
	PRINT(num = %d\n, 520);
	PRINT(Hello JING HE!\n);
	return 0;
}
