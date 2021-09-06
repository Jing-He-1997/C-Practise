#include <stdio.h>

int main()
{
	char *name;//悬空指针，这是非常危险的一件事情

	printf("What's your name:");
	scanf("%s", name);
	printf("Your name is %s\n", name);

	return 0;
}
