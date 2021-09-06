#include <stdio.h>

#define LINK(A, B, C) B##A##C
#define STR(s) # s
#define INT %d
#define NL \n
#define PRINT(A, B, C) printf(STR(INT NL), LINK(A, B, C))

int main(void)
{
	PRINT(2, 5, 0);
	return 0;
}
