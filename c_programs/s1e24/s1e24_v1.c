#include <stdio.h>

int main()
{
	char array[4][5]={0};
	char *target = &array[0][0];

	printf("int 类型在该系统所占的长度是:%d\n",sizeof(int));
	printf("array的地址是：%p\n",array);
	printf("array + 1的地址是：%p\n", array + 1);

	//printf("二维数组第一个元素的地址是：%p\n",target);
	
	return 0;
}
