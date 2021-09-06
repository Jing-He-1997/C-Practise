#include <stdio.h>
#include <math.h>


//600851475143这个数字没什么问题
int main()
{
	long long num,i,j,k,l,num1;
	_Bool flag = 1, flag1 = 1;
	printf("请输入一个合数：");
	
	// 输入一个数，判断这个数是否为合数，如果不是和数需要重新输入
	while(1)
	{
		scanf("%lld",&num);
		
		if(num == 4)
		{
			break;
		}
		for(long long n = 2; n < num / 2; n++)
		{
			if(!(num % n))
			{
				flag = 0;
				break;
			}
		}

		if(flag)
		{
			printf("%lld不是合数，请重新输入：",num);
		}
		else
		{
			break;
		}
		
	}
	
	//对数值较小的数字会出现计算错误
	k = (long long)sqrt(num);
	for(i = 5;i < k; i++)
	{
		if(num % i == 0)
		{
			l = (long long)sqrt(i);
			for(j = 2; j < l; j++)
			{
				if(!(i % j))
				{
					flag1= 0;
					break;	
				}
			}
			if(flag1)
			{	
				printf("%lld\n",i);
				num1 = i;
			}	
		}
	}

	printf("结果：%lld中最大的素数因子是%lld\n",num,num1);
	
	return 0;
}
