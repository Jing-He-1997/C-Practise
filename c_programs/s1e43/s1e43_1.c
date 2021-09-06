#include <stdio.h>

int main(void)
{
	struct Student
	{
		int id;
		int gender;
		unsigned long num;
		char email[40];
	};

	int n, i;
	printf("请输入需要录入的数据数量：");
	scanf("%d", &n);
	
	struct Student student[n];
	struct Student *pt;
	pt = student;
	for(i = 0; i < n; i++)
	{
		printf("请录入第%d个学生的数据...\n", i+1);
		printf("请输入学生ID:");
		scanf("%d", &((pt+i) -> id));
		printf("请输入学生的性别(1/0):");
		scanf("%d", &((pt+i) -> gender));
		printf("请输入学生QQ号:");
		scanf("%lu", &((pt+i) -> num));
		printf("请输入学生Email地址:");
		scanf("%s", (pt+i) -> email);
	}

	printf("\n===========数据录入完毕==============\n\n");
	printf("以下是录入的所有男生的数据：\n");
	for(i = 0; i < n; i++)
	{
		if(student[i].gender == 0)
		{
			continue;
		}
		printf("ID:%d\n", (pt+i) -> id);		
		printf("QQ:%lu\n", (pt+i) -> num);		
		printf("Email:%s\n", (pt+i) -> email);		
	}
	printf("以下是录入的所有女生的数据：\n");
	for(i = 0; i < n; i++)
	{
		if(student[i].gender == 1)
		{
			continue;
		}
		printf("ID:%d\n", (pt+i) -> id);		
		printf("QQ:%lu\n", (pt+i) -> num);		
		printf("Email:%s\n", (pt+i) -> email);		
	}
	return 0;
}
