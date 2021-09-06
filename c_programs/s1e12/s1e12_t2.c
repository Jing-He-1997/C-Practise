#include <stdio.h>

int main()
{
	float i;
	
	printf("请输入一个小数:");
	scanf("%f",&i);

	//switch(i)
	//{
	//	case 1.2: printf("1.2\n"); break;
	//	case 2.2: printf("2.2\n"); break;
	//	case 3.2: printf("3.2\n"); break;
	//	case 4.2: printf("4.2\n"); break;
	//	case 5.2: printf("5.2\n"); break;
	//} 
	//报错：case标号不能还原为一个整常量；
	//case后面只能跟整型常量或整型类型的常量表达式；
	//字符型也可以（因为在内存中是ASCII值，也是整型。

	return 0;
}
