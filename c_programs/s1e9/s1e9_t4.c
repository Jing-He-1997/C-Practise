#include <stdio.h>

int main()
{
	float fah, cel;

	printf("请输入摄氏度：");
	scanf("%f",&cel);

	fah = cel * 9 / 5 + 32;
	printf("转化为华氏度为：%.2f\n", fah);
	
	return 0;
}
