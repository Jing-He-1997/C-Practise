#include <stdio.h>

int main(void)
{
	char *array[5] = {"FishC", "Five", "Star", "Good", "WoW"};
	char *(*target)[5] = &array;
	int i, j;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; *(*(*target+i)+j) != '\0'; j++)
		{
			printf("%c ", *(*(*target+i)+j));
		}
		putchar('\n');
	}

	return 0;
}
