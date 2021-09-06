#include <stdio.h>

int main(void)
{
	struct Test
	{
		unsigned int a:100;
		unsigned int b:200;
		unsigned int c:300;
		unsigned int  :424;
	};



	return 0;
}
