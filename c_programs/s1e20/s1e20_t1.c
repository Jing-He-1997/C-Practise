#include <stdio.h>

int main()
{
	char slogans [5][100]={
		"I LOVE FISHC.COM!",
		"KEEP MOVING!",
		"IMPROSSIBLE IS NOTHING!",
		"JUST DO IT!",
		"I AM WHAT I AM!"};

	for(int i = 0; i < 5; i++)
	{
	//	for(int j = 0; j < 23;j++)
	//	{
	//		printf("%c",slogans[i][j]);
	//	}
		printf("%s\n",slogans[i]);

	putchar('\n');
	}

	return 0;
}
