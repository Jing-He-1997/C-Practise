#include <stdio.h>
void get_array(int b[10]);

void get_array(int b[10])
{
	printf("sizeof(b) = %d\n", sizeof(b));
}
int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	get_array(a);
	printf("sizeof(a) = %d\n", sizeof(a));
	return 0;
}
