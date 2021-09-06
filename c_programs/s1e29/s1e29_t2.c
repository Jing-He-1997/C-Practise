#include <stdio.h>

void func(int b[][3]);

void func(int b[][3])
{
	printf("%d\n",b[2][2]);
}

int main(void)
{
	int a[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}};

	//编译器会发出警告，func会把a[3][4]强制转换成a[][3]
	func(a);

	return 0;
}

