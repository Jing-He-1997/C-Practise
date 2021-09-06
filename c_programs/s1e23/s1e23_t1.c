#include <stdio.h>

int main()
{
	int str[]={1, 2, 3, 4, 5};
	
	for(int i = 3; i < 5; i++)
	{
		printf("%d\n", str[3]++);
		//printf("%d\n",*(str + 3)++);// str不是左值！！
	}

	return 0;
}
