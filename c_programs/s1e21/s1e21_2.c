#include <stdio.h>

int main()
{
	int a;
	int b;
	int res = 0;

	printf("请输入一个整数：");
	scanf("%d",&a);
	printf("%d^3== ",a);

	b = a * a * a;

	printf("%d == ",b);

	if(a % 2 == 0)
	{	// 7 9 11 13 15 17 19 21 23 25 27 29
		int count = 2*a;
		int num[count];
		for(int i = 0; i < a; i++)
		{
			num[a -(i+ 1)] = a*a / 2 - 1 - 2 * i;
			num [a + i] = a*a / 2 + 1 + 2 * i;
			res = res + num[a - (i+ 1)]+ num[a + i];
		}
		if(res == b)
		{
			for(int j = 0; j < a * 2;j++)
			{
				if(j + 1 == a * 2)
				{
					printf(" %d\n",num[j]);
				}
				else
				{
					printf(" %d+",num[j]);
				}
			}
		}
	}
	if(a % 2 != 0)
	{
		int num1[a];
		for(int k = 0; k <= a / 2; k++)
		{
			num1[a/2 -k]= a * a -2*k;
			num1 [a/2 + k]= a * a + 2*k;
		}
		for(int i1 = 0; i1 < a; i1++)
		{
			res += num1[i1];
		}

		if(res == b)
		{
			for(int j1 = 0; j1 < a ;j1++)
			{
				if(j1 + 1 == a)
				{
					printf(" %d\n", num1[j1]);
				}
				else
				{	
					printf(" %d + ",num1[j1]);
				}
			}
		}
	}

	return 0;
}
