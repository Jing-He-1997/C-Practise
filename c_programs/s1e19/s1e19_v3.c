#include <stdio.h>
#include <string.h>
int main()
{
	char str1[]="To be or not to be, this is a question";
	char str2[40];

	strncpy(str2,str1, 5);//最后那个参数是拷贝字符个数（不包括'\0'）
	printf("%s\n",str2);

	return 0;
}
