#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])//*argv[] 是一个指针，指向一个字符指针或者字符串指针
{
	int sum = 0;

	for(int i = 0; i < argc; i++)
	{
		sum += atoi(argv[i]);
	}

	printf("sum = %d\n", sum); 

	return 0;
}
