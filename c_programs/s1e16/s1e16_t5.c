#include <stdio.h>

int main()
{
	int size;
	printf("请输入一个size：");
	scanf("%d",&size);

	float cost = 1,flag = 1, bill;
	while(1)
	{
		if(size > 12)
		{
			cost = cost * 1.05;
			flag = 2;
		}
		break;
	}

		bill = cost * flag;

	printf("bill = %.2f\n",bill);
	
	return 0;
}
