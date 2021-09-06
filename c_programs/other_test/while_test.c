#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = "I love FishC.com!"; //17个字符组成的字符串
	int i = 0;
	while(str[i++] != '\0')
		;

	printf("Last character in the string str[16] = %c\n", str[16]);
	printf("strlen(str) = %d\n", strlen(str));
	printf("After loop, i = %d\n", i);

	return 0;
}
