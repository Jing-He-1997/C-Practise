#include <stdio.h>

int main(void)
{
	char *array[5] = {"FishC", "Five", "Star", "Good", "WoW"};
	char *(*target)[5] = &array;
	int i, j;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if((*target)[j][i] == '\0')
			{
				break;
			}

			printf("%c ", (*target)[j][i]);
		}

		putchar('\n');
	}

	return 0;
}
