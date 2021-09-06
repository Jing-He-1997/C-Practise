#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100],str2[100];
	_Bool flag = 1;
	int cmp_num;
	printf("请输入第一个字符串：");
	scanf("%s",&str1);

	printf("请输入第二个字符串：");
	scanf("%s",&str2);

	printf("请输入比较的字符数：");
	scanf("%d",&cmp_num);

	for(int i = 0;i < cmp_num;i++)
	{
		if(str1[i] != str2[i])
		{
			flag = 0;
			printf("比较的结果为：%d\n",str1[i]-str2[i]);
			break;
		}

	}

	if(flag)
	{
		printf("比较的结果为:0\n");
	}

	return 0;
}
