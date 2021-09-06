#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct Stu
{
	char name[20];
	int num;
	int score;
} STU, *PTRSTU;

int main(void)
{
	FILE *fp;
	int i;
	STU stu_2;
	PTRSTU stu;	
	stu = (PTRSTU)malloc(sizeof(STU) * N);

	if(stu == NULL)
	{
		printf("内存申请失败!\n");
		exit(1);	
	}

	printf("请输入学生的信息(姓名 学号 成绩):\n");	
	for(i = 0; i < N; i++)
	{
		scanf("%s %d %d", stu[i].name, &stu[i].num, &stu[i].score);
	}

	if((fp = fopen("s1e59_v2_1.txt", "wb")) == NULL)
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}
	
	fwrite(stu, sizeof(STU), N, fp);
	
	fclose(fp);

	if((fp = fopen("s1e59_v2_1.txt", "rb")) == NULL)
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}
	
	//三个参数分别是 指针指向FILE类型, offset, 位置指示器位置
	fseek(fp, sizeof(STU), SEEK_SET);

	fread(&stu_2, sizeof(STU), 1 ,fp);

	printf("第二个同学的信息是:%s %d %d\n", stu_2.name, stu_2.num, stu_2.score);

	fclose(fp);
	free(stu);

	return 0;
}
