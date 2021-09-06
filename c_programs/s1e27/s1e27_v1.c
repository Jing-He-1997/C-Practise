#include <stdio.h>

int main()
{
	//pi现在是只读
	const float pi = 3.14;

	printf("pi = %f\n",pi);
//	pi =  3.1415; 这里会报错，因为不能修改！！
	return 0;
}
