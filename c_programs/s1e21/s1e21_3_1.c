#include <stdio.h>
#include <stdbool.h>

int main()
{
	int i, j, n, count, cubed, sum = 0;
	bool result = true;
	char answer;

	printf("请输入一个整数：");
	scanf("%d",&count);

	int array[count][4];

	for(n = 3; n<=count; n++)
	{
		array[n][0]= 0; //初始化为0，用于验证
	}
	
	for(n = 3; n<= count; n++)
	{
		cubed = n * n * n;
		for(i = 1; i < cubed; i += 2)
		{
			for(j = i; j < cubed; j += 2)
			{
				sum += j;
				if(sum == cubed)
				{
					array[n][0]= cubed;
					array[n][1]= i;
					array[n][2]= i+ 2;
					array[n][3]= j;

					goto FINDIT;
				}

				if(sum > cubed)
				{
					sum = 0;//如果没找到，在i+=2之前先重置sum为0
					break;
				}
			}
		}
FINDIT: 	sum = 0;// 找到后在进入下一个n之前先将sum重置为0
	}
	
	for(n = 3; n <= count; n++)
	{
		if(array[n][0] == 0)
		{
			result = false;
			break;
		}
	}

	if(result)
	{
		printf("经验证，3 ～%d之间的所有整数均符合尼科彻斯定理！\n\n",count);

		printf("是否打印所有式子(y/n):");
		getchar();//上一次scanf的空格需要输出
		scanf("%c",&answer);
	}
	else
	{
		printf("验证失败：整数%d无法找到对应的连续奇数！\n",n);
	}

	if(answer == 'y')
	{
		for(n = 3; n <= count; n++)
		{
			if(array[n][3]-array[n][1]> 4)
			{
				printf("%d^3 == %d == %d + %d +...+ %d\n",n,array[n][0], array[n][1], array[n][2], array[n][3]);
			}
			else
			{
				printf("%d^3 == %d == %d + %d + %d\n",n,array[n][0], array[n][1], array[n][2], array[n][3]);
			}
		}
	}

	return 0;
}
