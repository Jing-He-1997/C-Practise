#include <stdio.h>

#define STR(s) # s
int main(void)
{
	printf(STR(Hello          %s num = %d), STR(HEJING), 520);
	return 0;
}
