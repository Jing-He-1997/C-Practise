#include <stdio.h>

int main()
{
//	void a;错误 void无法定义变量或者字段！！
//	printf("%d\n", sizeof(a));
	printf("%d\n",sizeof(void *));
	return 0;
}
