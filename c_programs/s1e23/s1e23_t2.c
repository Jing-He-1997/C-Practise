#include <stdio.h>

int main()
{
	int a[5]= {1, 2, 3, 4, 5};
	int *b;

	b = &a[3];
	printf("%d\n",b[-2]);
	printf("%d\n",*(b - 2));//这两个是东西是相等的！

	return 0;
}
