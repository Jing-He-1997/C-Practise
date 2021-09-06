#include <stdio.h>

int main(void)
{
	struct Date
	{
		int year;
		int month;
		int day;
	};

	struct Student
	{
		int id;
		char name[20]; 	//当数组元素个数为20时，它是与int类型对齐的（4字节）
				//当数组元素个数为21，此时与int类型没有对齐，需要增加额外的3个字节
		struct Date date;
	};

	struct Student stu[20];

	printf("size of stu = %d\n", sizeof(stu));
	
	return 0;
}
