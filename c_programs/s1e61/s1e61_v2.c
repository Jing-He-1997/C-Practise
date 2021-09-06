#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[1024];	// 因为使用setvbuf函数需要指定一个用户分配的缓冲区
			//如果不指定，那么函数会自动分配一个指定尺寸的缓冲区
	
	memset(buf, '\0', 1024);	// 初始化内存空间中的内容， 在malloc那里讲过

	setvbuf(stdout, buf, _IOFBF, 1024);

	fprintf(stdout, "My name is Jing He! How's going bro!\n");
	
	fflush(stdout);
	
	fprintf(stdout, "You can see me after you input any character(s)!\n");

	getchar();

	return 0;
}
