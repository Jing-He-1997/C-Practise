#include <stdio.h>

int main()
{
	char *array[5]={"FishC", "Five", "Star", "Good", "WoW"};
	char *(*target)[5] = &array;
	int i, j;

	int length = 0;
	int count[5];
	for(i = 0; i < 5; i++)
	{
		count[i] = 0;
		while(1)
		{
			//第一个字符串中的第一个字符：*(*(*target))
			//target : 指向字符串地址的地址的指针
			//*target：指向字符串的地址，是target指针的值
			//*(*target):指向字符串中的字符的地址，是*target的值
			//*(*(target)):字符的值
			if(*(*(*target + i)+ count[i]) == '\0')
			{
				break;
			}
			count[i]++;
		}
		if(count[i] > length)
		{
			length = count[i];
		}
	}

//	printf("%d\n",length);

	for(i = 0; i < length; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(count[j] < i)
			{
				break;
			}
			printf("%c ",*(*(*target + j)+ i));
		}
		printf("\n");
	}
	return 0;
}
