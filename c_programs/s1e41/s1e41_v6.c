#include <stdio.h>

#define TOGETHER(x, y) x ## y
int main(void)
{
	printf("%d\n", TOGETHER(2, 50));
	return 0;
}
