#include <stdio.h>

#define MAX 1024
int main()
{
	char str1[MAX];
	char str2[MAX];

	char *target1 = str1;
	char *target2 = str2;
	_Bool flag = 1;
	int num = 1;
	

	printf("请输入第一个字符串：");
	fgets(str1, MAX, stdin);

	printf("请输入第二个字符串：");
	fgets(str2, MAX, stdin);

	while(*target1!= '\0'|| *target2!='\0')
	{
		if(*target1++!= *target2++)
		{
			flag = 0;
			printf("两个字符串不完全相同，第%d个字符串出现不同\n",num);
			break;
		}
		num++;
	}

	//printf("%d\n",num);

	if(flag)
	{
		printf("两个字符串完全一致！\n");
	}

	return 0;
}
