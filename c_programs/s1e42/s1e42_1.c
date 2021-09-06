#include <stdio.h>

#define MAXSIZE 20
struct Student
{
	int id;
	int gender;
	unsigned long num;
	char email[MAXSIZE];
} student;

int main(void)
{

	printf("请输入学生ID:");
	scanf("%d", &student.id);
	printf("请输入学生性别(1/0):");
	scanf("%d", &student.gender);
	printf("请输入QQ号:");
	scanf("%d", &student.num);
	printf("请输入Email地址:");
	scanf("%s", student.email);

	printf("\n=============数据录入完毕===============\n\n");

	printf("当前结构体变量中的数据是:\n");
	printf("ID: %d\n", student.id);
	if(student.gender == 1)
	{
		printf("性别:男\n");
	}
	if(student.gender == 0)
	{
		printf("性别:女\n");
	}

	printf("QQ号是:%lu\n", student.num);
	printf("Email是:%s\n", student.email);
	return 0;
}
