#include <stdio.h>

void swap(int*, int*);

void swap(int *x, int *y)
{
	printf("In swap, 函数体执行前,x = %d, y = %d\n", *x, *y);
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	printf("In swap, 函数体执行后,x = %d, y = %d\n", *x, *y);

}

int main()
{
	int x = 3, y = 5;
	printf("In main, swap执行前,x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("In main, swap执行后,x = %d, y = %d\n", x, y);
	return 0;
}
