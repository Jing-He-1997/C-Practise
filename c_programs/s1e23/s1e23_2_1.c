#include <stdio.h>

int main()
{
	//array[5]里面的每个元素是字符串的指针，指向整个字符串， array[0]="FishC"
	char *array[5]={"FishC", "Five", "Star", "Good", "WoW"};
	//因为array[5]中存放的是指针，指向每个字符串；
	//(*target)表明是每一个字符串；
	//*(*target)[5]这样定义指向的是每一个字符串中的每一个字符
	char *(*target)[5]= &array;
	int i, j;

	for(i = 0; i < 5; i++)
	{
		for(j = 0;(*target)[i][j]!= '\0'; j++)
		{
			printf("%c ", (*target)[i][j]);
		}
		printf("\n");
	}

	printf("target = %p\n",target);
	printf("target + 1 = %p\n",target + 1);
	
	printf("array = %p\n", array);
	printf("array + 1=%p\n",array + 1);
	
	printf("*target = %p, %s\n",*target, **target);
	printf("*target + 1 = %p, %s\n",*target + 1, *(*target + 1));
	
	printf("*array = %s\n", *array);
	printf("*(array + 1) = %s\n",*(array + 1));

	printf("**array = %c\n",**array);
	printf("*(*array + 1) = %c\n",*(*array + 1));	
	

	return 0;
}
