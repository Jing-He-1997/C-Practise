#include <stdio.h>

#define STR(s) # s
int main(void)
{
	printf("%s\n", STR(HEJING));
	return 0;
}
