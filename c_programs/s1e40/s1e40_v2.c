#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int main(void)
{
	int x, y;
	printf("请输入两个整数:");
	scanf("%d%d", &x, &y);
	
	printf("较大的那个数为:%d\n", MAX(x, y));
	
	return 0;
}
