#include <stdio.h>

int main()
{
	int a[10];
	int mark;

	for(int i = 0; i < 10; i++)
	{
		printf("成绩：");
		scanf("%d",&mark);
		
		a[i] = mark;
	}

	printf("成绩为：");
	
	for(int i = 0; i < 10; i++)
	{	
		printf("%d ",a[i]);
	}

	printf("\n");
	return 0;
}
