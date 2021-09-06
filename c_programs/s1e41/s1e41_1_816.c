#include <stdio.h>

#define FIFTH_ARG(A, B, C, D, E, ...) E
int main(void)
{
	printf("第五个参数是%s\n", FIFTH_ARG("APPLE", "TWIST", 3, 4, "FishC", 666));
	return 0;
}
