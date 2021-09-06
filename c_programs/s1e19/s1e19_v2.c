#include <stdio.h>
#include <string.h>
int main()
{
	char str1[]="HE JING";
	char str2[]="JING";
	char str3[]="in";

	strcpy(str2,str1);
	strcpy(str3,str1);
	printf("%s\n",str2);
	printf("%s\n",str3);	//这里即使str2和str3分配的空间不足以存放str1，但最终
				//还是可以显示str1的内容，str2和str3中的'\0'被覆盖了
	printf("sizeof str2 :%d sizeof str3:%d\n",sizeof(str2),sizeof(str3));
	printf("length str2 :%d length str3:%d\n",strlen(str2),strlen(str3));

	return 0;
}
