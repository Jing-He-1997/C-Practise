#include <stdio.h>

int main()
{
	char *array[5] = {"FishC", "Five", "Star", "Good", "WoW"};
	char *(*target)[5] = &array;
	int i ,j;

	for(i = 0; i < 5; i++)
	{
		//*target + i : 指向每个字符串地址的地址
		//*(*target + i) ： 指向每个字符串地址（相当于每个字符串的首地址）
		//*(*target + i ) + j :指向到每个字符串的每个字符
		for(j = 0; *(*(*target + i)+ j)!= '\0'; j++)
		{
			printf("%c ",*(*(*target + i) + j));
		}

		printf("\n");
	}

	return 0;
}
