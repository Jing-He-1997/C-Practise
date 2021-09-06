#include <stdio.h>

int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	//pi是指向array[2]的地址
	int *pi = &array[2];

	printf("*pi = %d\n", *pi);
	void *pv;

	pv = pi;
	printf("pv的地址是 = %p\n", pv);
	pv++;//这里pv++相当于pv的地址加上0x1,而整型的长度是0x4，所以最后输出的pi会是一个奇怪的值
	printf("pv++后，pv的地址是 = %p\n",pv);
	pi = pv;

	printf("pv++后，*pi = %d\n",*pi);

	return 0;
}
