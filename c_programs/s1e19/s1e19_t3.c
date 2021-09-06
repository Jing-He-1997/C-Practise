#include <stdio.h>
#include <string.h>

int main()
{
	char str[10]; //未初始化！

	strncat(str,"My name is Jing He!",sizeof(str));
	
	printf("%s\n",str);
	return 0;
}
