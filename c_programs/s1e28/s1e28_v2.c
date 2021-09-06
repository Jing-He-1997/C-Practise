#include <stdio.h>
int sum(int n);

int sum(int n)
{
	int res = 0;
	for(int i = 1; i<=n; i++)
	{
		res += i;
	}

	return res;
}
int main()
{
	int n;
	printf("请输入n的值：");
	scanf("%d",&n);

	printf("结果为%d\n", sum(n));

	return 0;	
}
