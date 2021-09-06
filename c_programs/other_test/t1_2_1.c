#include <stdio.h>

int main()
{
	long a = 1, b = 2, c ,sum = 0;

	do
	{
		if(!(b%2))
		{
			sum += b;
		}

		c = a + b;
		a = b;
		b = c;
	}while(c < 4000000);

	printf("%ld\n",sum);
	return 0;
}
