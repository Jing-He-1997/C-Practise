#include <stdio.h>

int main()
{
	int array[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int (*p)[10]=&array;// 必须定义边界！！，不然会报错！！

	printf("%d\n",*(*(p+1) - 6)); //p + 1 指向下一个 10个元素的数组

	return 0;
}
