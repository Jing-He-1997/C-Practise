#include <stdio.h>
#include <string.h>

int main()
{
	char str[]="中";

	int length = strlen(str);
	for(int i = 0; i < length; i++)
	{
		printf("str[%d] = %d\n",i,str[i]);
	}
	
	return 0;
}
