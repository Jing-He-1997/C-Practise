#include <stdio.h>

int main()
{
	char name[256];
	double height,weight;

	printf("请输入您的姓名：");
	scanf("%s",name);
	
	printf("请输入您的身高（cm）：");
	scanf("%lf",&height);

	printf("请输入您的体重（kg）：");
	scanf("%lf",&weight);

	printf("=======正在换算中..========\n");

	height = height / 2.54;
	weight = weight / 0.453;

	printf("%s的身高是%.2lf（in），体重是%.2lf（lb）。\n", name, height, weight);

	return 0;
}
