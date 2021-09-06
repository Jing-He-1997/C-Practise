#include <stdio.h>
#include <string.h>

int main()
{
	char str1[]="He";
	char str2[]="Jing";

	if(strlen(str1)-strlen(str2)< 0)
	{
		printf("字符串\"%s\"比字符串\"%s\"短！\n",str1,str2);
	}
	else
	{
		printf("字符串\"%s\"比字符串\"%s\"长！\n",str1,str2);
	}

	return 0;
}
