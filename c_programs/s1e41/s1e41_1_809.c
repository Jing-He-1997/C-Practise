#include <stdio.h>

#define FIFTH_ARG(A1, A2, A3, A4, A5, ...) A5
int main(void)
{
	printf("第五个参数是:%s\n", FIFTH_ARG("APPLE", "TWIST", 3, 4, "FISHC", 666));
	return 0;
}
