#include <stdio.h>
#include <string.h>

int main()
{
	char *str = "My name is Jing He";

	int length = strlen(str);//这样做可以提高效率，减少strlen()的调用次数

	for(int i = 0; i < length; i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");

	return 0;
}
