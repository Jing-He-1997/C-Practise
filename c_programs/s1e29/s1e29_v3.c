#include <stdio.h>
void get_array(int a[10]);

void get_array(int a[10])
{
	printf("In get_array, before implementation:");
	for(int i = 0; i <10; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	int temp;
	for(int i = 0; i < 5; i++)
	{
		temp = a[i];
		a[i] = a[9 - i];
		a[9 - i] = temp;
	}

	a[5] = 520;

	printf("In get_array, after implementation:");
	for(int i = 0; i <10; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

}
int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	get_array(a);
	printf("In main, after implementing get_array: ");
	
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
	return 0;
}
