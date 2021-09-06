#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 5

int main(void)
{
	int i;
	time_t t;

	srand((unsigned)time(&t));

	for(i = 0; i < NUM; i++)
	{
		printf("%d\n", rand() % 100);// 产生0 - 99随机数
	}

	return 0;
}

	
