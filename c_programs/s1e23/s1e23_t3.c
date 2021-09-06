#include <stdio.h>

// a = a+b, b = a-b, a = a-b
#define SWAP(a ,b) (a += b, b = a-b, a -=b)
int main()
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, j;

	printf("请输入i和j:");
	scanf("%d %d", &i, &j);

	SWAP(array[i], array[j]);

	//因为当i和j相等时，他们指向的数组中的位置也是一样的，所以a-b一直等于0
	printf("array[i] = %d\n", array[i]);
	printf("array[j] = %d\n", array[j]);
	
	return 0;
}
