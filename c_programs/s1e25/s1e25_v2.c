#include <stdio.h>

int main()
{
	int num = 1024;
	int *pi = &num;
	char *ps = "FishC";

	void *pv;

	pv = pi;
	printf("pi:%p pv:%p\n",pi, pv);
	printf("pv的值为：%d\n",*(int *)pv);

	pv = ps;
	printf("ps:%p pv:%p\n",ps, pv);
	printf("pv的值为：%s\n",(char *)pv);

	return 0;
}
