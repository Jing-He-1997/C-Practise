#include <stdio.h>

void func();//1. 声明需要加;

int main()
{
	func();
	return 0;
}

void func()
{
	printf("My name is Jing He\n");//2. printf

	//3. 不能加return 0;
}//4. 定义不需要分号;
