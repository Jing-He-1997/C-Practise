#include <stdio.h>
#include <string.h>
int main()
{
	char *array[5] = {"FishC", "Five", "Star", "Good", "WoW"};
	char *(*target)[5] = &array;
	int i ,j;

	int length = 0;
	
	for(i = 0; i < 5; i++)
	{
		if(strlen((*target)[i]) > length)
		{
			length = strlen((*target)[i]);
		}
	}

//	printf("%d\n",length);

	for(i = 0; i < length; i++)
	{
		for(j = 0; j <  5;j++)
		{
			if(strlen((*target)[j]) < i)
			{
				break;
			}

			printf("%c ",(*target)[j][i]);
		}
		printf("\n");
	}
	return 0;
}
