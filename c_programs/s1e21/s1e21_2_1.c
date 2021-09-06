#include <stdio.h>

int main()
{
	int i, j, n, cubed, sum = 0;

	printf("请输入一个整数：");
	scanf("%d",&n);

	cubed = n * n * n;

	for(i = 1; i < cubed; i += 2)//i为表达式中的第一个奇数
	{
		for(j = i; j < cubed; j += 2)//j为表达式中的最后一个奇数
		{
			sum += j;
			if(sum == cubed)
			{
				if(j - i > 4)
				{
					printf("%d = %d + %d + ...+ %d\n",cubed, i, i+2, j);
				}
				else
				{
					printf("%d = %d + %d + %d\n",cubed, i, i+2, j);
				}
				goto FINDIT;
			}
			

			if(sum > cubed)
			{
				sum = 0;
				break;
			}
		}
	}

FINDIT: return 0;
}
