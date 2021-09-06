#include <stdio.h>
#include <string.h>

int main()
{
	char str1[]="My name is Jing He!";

	str1[7]='\0';

	printf("sizeof str1 = %d\n",sizeof(str1));
	printf("strlen str1 = %d\n",strlen(str1));

	return 0;
}
