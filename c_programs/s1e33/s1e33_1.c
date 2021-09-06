#include <stdio.h>

void func1(int, int);
void func2(const int, const int);

int global_var1;
int global_var2;

static int file_static_var1;
static int file_static_var2;

void func1(int func1_param1, int func1_param2)
{
	static int func1_static_var1;
	static int func1_static_var2;

	printf("addr of func1_param1: %010p\n", &func1_param1);
	printf("addr of func1_param2: %010p\n", &func1_param2);
	printf("addr of func1_static_var1: %010p\n", &func1_static_var1);
	printf("addr of func1_static_var2: %010p\n", &func1_static_var2);
}

void func2(const int func2_const_param1, const int func2_const_param2)
{
	int func2_var1;
	int func2_var2;
	
	printf("addr of func2_const_param1: %010p\n", &func2_const_param1);
	printf("addr of func2_const_param2: %010p\n", &func2_const_param2);
	printf("addr of func2_var1: %010p\n", &func2_var1);
	printf("addr of func2_var2: %010p\n", &func2_var2);
}

int main()
{
	char *string1="JING";
	char *string2="HE";

	printf("addr of func1: %010p\n", func1);
	printf("addr of func2: %010p\n", func2);

	printf("addr of string1: %010p\n", string1);
	printf("addr of string2: %010p\n", string2);

	printf("addr of global_var1: %010p\n", &global_var1);
	printf("addr of global_var2: %010p\n", &global_var2);

	printf("addr of file_static_var1: %010p\n", &file_static_var1);
	printf("addr of file_static_var2: %010p\n", &file_static_var2);

	func1(1, 2);
	func2(3, 4);

	return 0;	
}
