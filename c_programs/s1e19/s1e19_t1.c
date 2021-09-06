#include <stdio.h>
#include <string.h>

int main()
{
	char str1[]="Original";
	char str2[]="New";

	strcpy(str1,str2);
	printf("%s\n",str1);

	return 0;
}
