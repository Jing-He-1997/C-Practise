#include <stdio.h>

int main()
{
	int original_num;
	int a;
	int b;
	char cond;
	printf("请输入一个整数：");
	scanf("%d",&original_num);
	getchar();

	printf("是否打印结果（y/n）：");
	scanf("%c",&cond);
	for(a = 3; a<= original_num; a++)
	{
		int res = 0;
		if(cond == 'y')
		{
			printf("%d^3== ",a);
		}

		b = a * a * a;

		if(cond == 'y')
		{
			printf("%d == ",b);
		}

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
						if(cond == 'y')
						{
							printf(" %d\n",num[j]);
						}
					}
					else
					{
						if(cond == 'y')
						{
							printf(" %d+",num[j]);
						}
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
						if(cond == 'y')
						{
							printf(" %d\n", num1[j1]);
						}
					}
					else
					{	if(cond == 'y')
						{	
							printf(" %d + ",num1[j1]);
						}
					}
				}
			}
		}
	}

	return 0;
}
