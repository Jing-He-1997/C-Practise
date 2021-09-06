#include <stdio.h>

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int (*p1)[10] = &a;
	int *p2 = &a[0];

	//虽然地址是一样的，但&a取的的跨度是40个字节(16进制表示28h)，而&a[0]的跨度是4个字节
	printf("&a(p1) = %p, &a[0](p2) = %p\n", p1, p2);
	printf("p1+1 = %p, p2+1 = %p\n", p1+1, p2+1);
	

	return 0;
}
