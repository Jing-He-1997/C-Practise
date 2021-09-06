#include <stdio.h>

void up_and_down(int n);

void up_and_down(int n)
{
	printf("%d ", n);
	if(n > 0)
	{
		up_and_down(--n);
	}
	printf("%d ", n);
}

int main(void)
{
	int n;

	printf("请输入一个整数：");
	scanf("%d",&n);
	
	up_and_down(n); //4 up_and_down(3) 3
			//3 up_and_down(2) 2
			//2 up_and_down(1) 1
			//1 up_and down(0) 0
			//0 0
	putchar('\n');

	return 0;
}
