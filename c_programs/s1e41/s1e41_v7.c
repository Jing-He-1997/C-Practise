#include <stdio.h>

#define SHOWLIST(...) printf(# __VA_ARGS__)
int main(void)
{
	SHOWLIST(HEJING, 520, 3.14\n);
	return 0;
}
