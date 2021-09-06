#include <stdio.h>

int main()
{
	int i;
	
	printf("请输入成绩:");
	scanf("%d",&i);

	//switch(i)
	//{
	//	case i >= 90 && i <= 100: printf("A\n"); break;
	//	case i >= 80 && i < 90: printf("B\n"); break;
	//	case i >= 70 && i < 80: printf("C\n"); break;
	//	case i >= 60 && i < 70: printf("D\n"); break;
	//	case i < 60 && i >= 0: printf("E\n"); break;
	//	default:  printf("请输入合法的数字！\n"); break;
	//} 
	//报错：case标号不能还原为一个整常量；
	//case后面只能跟整型常量或整型类型的常量表达式；
	//字符型也可以（因为在内存中是ASCII值，也是整型。

	return 0;
}
