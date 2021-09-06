#include <stdio.h>

int main()
{
	char temp[5]= {1, 2, 3, 4, 5};
	char (*p)[5] = &temp;//(*p)[5]存放的是数组中每个元素的地址，所以要将temp数组看					作是一个整体取数组的地址（&），如果不加&也可以，因为将					数组看作整体取地址，得到的地址也是temp[0]，但是系统会					警告说初始化指针类型不匹配。

	for(int i = 0; i < 5; i++)
	{
		printf("%d\n",*(*p + i));//*p = temp[0]的地址  *(*p) = temp[0]的值
	}

	return 0;
}
