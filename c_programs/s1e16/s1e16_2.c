#include <stdio.h>

int main()
{
	int money = 400;
	int year = 0;
	while(money>0)
	{
		year++;
		money = money - 50;
		money = 1.08 * money;
		
	}

	printf("%d年之后，你败光了所有家产，再次回到一贫如洗\n", year);
	return 0;
}
