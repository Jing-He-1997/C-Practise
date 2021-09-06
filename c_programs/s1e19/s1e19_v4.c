#include <stdio.h>
#include <string.h>
int main()
{
	char str1[]="HE JING";
	char str2[]="JING";

	strcat(str2,str1);
	printf("%s\n",str2);

	return 0;
}
