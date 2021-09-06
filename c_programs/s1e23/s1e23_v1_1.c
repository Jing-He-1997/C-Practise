#include <stdio.h>

int main()
{
	char str[]={"My name is Jing He"};
	int length = 0;

	// str存储的地址是str[0]的地址，并且不会发生改变，所以不是左值
	// 程序报错
	while(*str++ != '\0')
	{
		length++;
	}

	printf("str的长度为%d\n",length - 1);

	return 0;
}
