#include <stdio.h>

int main()
{
	int score;
	int count = 0;
	while(1)
	{	
		printf("输入一个score：");
		scanf("%d",&score);
		if(score < 0)
		{
			printf("count = %d\n",count);
			break;
		}
		else
		{
			count++;
		}
	}

	return 0;
}
