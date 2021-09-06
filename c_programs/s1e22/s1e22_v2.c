#include <stdio.h>


int main()
{
	char str[128];
	printf("请输入你的名字：");
	scanf("%s",str);//这里不用使用取址符号&
	printf("你的名字是：%s\n",str);

	printf("str的地址是：%p\n",str);
	printf("str[0]的地址是：%p\n",&str[0]);//数组名的地址就是数组第一个元素的地址

	return 0;

}
