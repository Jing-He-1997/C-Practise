#include <stdio.h>

int main()
{
	int *p1;
	int *p3;
	int *p2 = NULL;

	printf("%d %d\n",*p1,*p3);
	printf("%d\n",*p2);//对NULL进行解引用是非法的！！！

	return 0;
}
