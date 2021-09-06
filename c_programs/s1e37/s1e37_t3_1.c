#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t count = 0;
	
	while(1)
	{
		malloc(10*1024);//当申请动态内存的粒度变大以后，系统会直接判定申请失败
		printf("%u\n", count++);
	}
	return 0;
}
