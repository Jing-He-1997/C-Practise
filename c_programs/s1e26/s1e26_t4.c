#include <stdio.h>

int main()
{
	char a[4][3][2]= {
		{
			{'a', 'b'}, {'c', 'd'}, {'e', 'f'}
		},
		{
			{'g', 'h'}, {'i', 'j'}, {'k', 'l'}
		},
		{
			{'m', 'n'}, {'o', 'p'}, {'q', 'r'}
		},
		{
			{'s', 't'}, {'u', 't'}, {'w', 'x'}
		}
		
	};

	char (*pa)[2] = &a[1][0];	//定位到第二行的第一个元素
	char (*ppa)[3][2]= &a[1];	//定位到第二行

	//pa的跨度是2 * char
	printf("pa: %p, pa + 1: %p\n", pa, pa +1);
	printf("%c\n", *(*(pa+8)+1));

	// ppa的跨度是 6 * char 指向的是a[4]
	printf("ppa: %p, ppa + 1: %p\n", ppa, ppa + 1);
	//*ppa的跨度是 2 * char 指向的是a[4][3]
	printf("*(ppa+2): %p, *(ppa+2)+1:%p\n",*(ppa+2), *(ppa+2)+1);
	//**ppa的跨度是1 * char 指向的是a[4][3][2]
	printf("**(ppa+2):%p, **(ppa+2)+1:%p\n", **(ppa+2), **(ppa+2)+1);
	printf("%c\n", *(**(ppa+2)+5));
	return 0;
}
