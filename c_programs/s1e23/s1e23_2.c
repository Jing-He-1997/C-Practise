#include <stdio.h>

//内存泄露了！！！

int main()
{
// 	array[i] : 指向每个字符串
	char *array[5]={"FishC", "Five", "Star", "Good", "WoW"};
//	char (*target)[5] = &array;
	int i, j;

	for(i = 0; i < 5; i++)
	{
//		printf("array[%d]= %s\n",i, array[i]);
//		printf("array[%d]= %c\n",i, *array[i]);
		
		//array[i]永远不会等于'\0'，所以相当于死循环
		for(j = 0; array[i]!= '\0';j++)
		{
			//*array[i]：指向每个字符串的第一个字符
			//加j过后相当于ASCII码 + j，而且j会一直++
			printf("%c ",*array[i]+ j);
		}
		printf("\n");
	}

	return 0;
}
