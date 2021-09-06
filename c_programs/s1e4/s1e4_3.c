#include <stdio.h>

int main()
{
	printf("打印五个字符:%c %c %c %c %c\n",'J','I','N','G','G');
	printf("前面用空格填充:%10d\n",2015);
	printf("前面用0填充:%010d\n",2015);
	printf("右对齐，保留两位:%10.2f\n",3.1416);
	printf("左对齐，保留三位:%-10.3f\n",3.1416);
	printf("右对齐，指数形式:%10e\n",520000.0);
	printf("左对齐，指数形式:%-10E\n",520000.0);

	return 0;
}
