#include <stdio.h>

void a();
void b();
void c();

int count;//在类型名前加上static，变量属性将变为internal, 其他文件无法访问

int main(void)
{
	a();
	b();
	c();
	b();

	printf("一共调用了%d次函数\n", count);
	return 0;
}
