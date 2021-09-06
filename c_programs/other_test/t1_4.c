#include <stdio.h>

int main()
{
	int sum, sum1 = 0, a, i; //sum的最大值= 998001

	for(sum = 998001; sum > 10000; sum--)
	{
		sum1 = 0;
		a = sum;
		//将sum的值倒过来
		while(a)
		{
			sum1 = 10 * sum1 + a % 10;
			a = a / 10;
		}
		
		if(sum1 == sum)
		{	//这个循环是用来取得两个乘数
			for(i = 100; i < 1000; i++)
			{
				if((sum1 % i == 0) && (sum1 / i < 1000))
				{
					goto FIND;
				}
			}
		}

		
	}
FIND:	printf("%d * %d = %d\n",i, sum1 / i, sum1);
	return 0;
}


