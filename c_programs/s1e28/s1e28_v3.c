#include <stdio.h>

int max(int n, int m);

int max(int n, int m)
{
	if(n > m)
	{
		return n;
	}
	else
	{
		return m;
	}
}
int main()
{
	int n, m;
	printf("请输入两个数字：");
	scanf("%d %d", &n, &m);

	int result = max(n, m);

	printf("%d和%d中较大的值是：%d\n", n, m, result);
	return 0;
}
