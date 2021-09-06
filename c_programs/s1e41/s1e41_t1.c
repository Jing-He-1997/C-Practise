#include <stdio.h>

#define STR(s) # s
int main(void)
{
	int num = 520;

	printf("%s\n", STR(num));
	
	return 0;
}
