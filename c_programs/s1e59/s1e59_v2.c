/*  Produce by Jing in 2021.08.27
 *  链表也可以在fread和fwrite中时用的 CSDN有例子
 * */

#include <stdio.h>
#include <stdlib.h>
/*
typedef struct Data
{
	char name[12];
	int num;
	int score;
} ElemType, *PtrElemType;
*/

typedef struct Student
{
	char name[20];
	int num;
	int score;
	struct Student *next;
} STUDENT, *PTRSTUDENT;

void addStudent(PTRSTUDENT *list);
void getInput(PTRSTUDENT student);
void releaseList(PTRSTUDENT *list);

void getInput(PTRSTUDENT student)
{
	scanf("%s %d %d", student->name, &student->num, &student->score);
}

void addStudent(PTRSTUDENT *list)
{
	PTRSTUDENT student = NULL;
	static PTRSTUDENT  tail;	//要让tail一直指向链表的尾部

	student = (PTRSTUDENT)malloc(sizeof(STUDENT));

	if(student == NULL)
	{
		exit(1);	
	}

	getInput(student);

	if(*list != NULL)
	{
		tail->next = student;
		student->next =NULL;	
	}
	else
	{
		*list = student;
		student->next =NULL;
	}

	tail = student;	
}

void releaseList(PTRSTUDENT *list)
{
	PTRSTUDENT temp = NULL;

	while(*list != NULL)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

int main(void)
{
	PTRSTUDENT list = NULL;
	STUDENT stu;
	FILE *fp;
	char ch;

	if((fp = fopen("s1e59_v2.txt", "wb")) == NULL)
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}

	printf("开始录入成绩（格式： 姓名 学号 成绩）:\n");
	do
	{
		addStudent(&list);
		getchar();	//输出缓冲区存留的空格
		printf("是否继续录入(Y/N):");
		ch = getchar();
	}while(ch == 'Y');	//未作保护措施
	
	while(list != NULL)
	{
		fwrite(list, sizeof(STUDENT), 1, fp);
		list = list->next;	
	}

	fclose(fp);

	if((fp = fopen("s1e59_v2.txt", "rb")) == NULL)
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}

	fseek(fp, sizeof(STUDENT), SEEK_SET);
	fread(&stu, sizeof(STUDENT), 1, fp);

	printf("%s(%d) 的成绩是: %d\n", stu.name, stu.num, stu.score);
	
	releaseList(&list);
	fclose(fp);	

	return 0;
}
