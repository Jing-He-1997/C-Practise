extern void func(void);//不加extern也不会出错，但是加上extern代码会更加清晰

int count = 520; //真正对count的定义是在这里

int main()
{
	func();

	return 0;
}
