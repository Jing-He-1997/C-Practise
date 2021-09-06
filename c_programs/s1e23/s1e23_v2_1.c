#include <stdio.h>

int main()
{
	char *p[5]= {
		"Abc",
		"Bcdef",
		"Cdefgh",
		"Defghij",
		"Efghijkl"};

	for(int i = 0; i< 5; i++)
	{
		printf("p[i] = %s\n",p[i]);
		printf("*p[i] = %c\n",*p[i]);//这里不能加*，因为是要输出字符串，需要定位的是字符串的地址
	}

	return 0;
}
