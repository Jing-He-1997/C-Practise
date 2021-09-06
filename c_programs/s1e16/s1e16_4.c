#include <stdio.h>
#include <math.h>

int main()
{
	//             aa
	//     3aa       4aa     5aa 6aa 7aa
	// 5aa 6aa 7aa  6aa 7aa 7aa
	//7aa
	//1 1
	//2 1
	//3 2
	//4 3
	//5 5
	//6 8
	int year; 
	int a = 1, b = 1,c;
	int i;
	printf("输入一个年份：");
	scanf("%d",&year);

	int month = year * 12;
	printf("month = %d\n",month);

	for(i = 3;i <= month; i++)
	{
		c = a + b;
		a = b;
		b = c; //找规律可得出这个结论;
	}

	printf("%d年后兔子的数量为%d对\n", year, c);
	
	return 0;
}
