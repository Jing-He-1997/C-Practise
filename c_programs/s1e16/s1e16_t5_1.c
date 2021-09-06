#include <stdio.h>

int main()
{
	int ibex;
	printf("输入一个ibex：");
	scanf("%d",&ibex);
	
	int sheds = 2;
	while(1)
	{
		if(ibex > 14)
		{
			sheds = 3;
		}
		break;
	}
	
	int help = 2 * sheds;

	printf("help的值为：%d\n",help);
	
	return 0;
}
