#include <stdio.h>

int main()
{
	int i = 0;
	while(i < 100)
	{
		if(i % 2)
		{
			i++;
			continue;
		}
		else
		{
			i++;
		}
	}
	
	return 0;
}
