#include <stdio.h>

int main(void)
{
	struct Student
	{
		char name[10]; 	/* 10 bytes (aligned with 16 bytes)*/
		int age;	/* total 4 bytes */
		int sex;	/* total 8 bytes (aligned with 16 bytes) */ 
		float score[4];	/* 4 bytes */
	} student;

	printf("size of student = %d\n", sizeof(student));
	return 0;
}
