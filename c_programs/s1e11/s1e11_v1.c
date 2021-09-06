#include <stdio.h>

int main()
{
	int mark;
	int true = 1;
	
	printf("学生的数学分数为：");
	while(true == 1)
	{
	scanf("%d",&mark);

	if (mark >= 90 && mark <= 100)
	{
		printf("该同学的等级为：A\n");
		break;
	}

	else if(mark >= 80 && mark < 90)
	{
		printf("该同学的等级为：B\n");
		break;
	}

	else if (mark>= 70 && mark < 80)
	{
		printf("该同学的等级为：C\n");
		break;
	}
 
	else if(mark>= 60 && mark < 70)
	{
		printf("该同学的等级为：D\n");
		break;
	}

	else if(mark >= 0 && mark < 60)
	{
		printf("该同学考试不及格，补考！\n");
		break;
	}
	else
	{
		printf("成绩输入有误，请重新输入：");
	}
	}

	return 0;
}
