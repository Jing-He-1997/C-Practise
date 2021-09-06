#include <stdio.h>
#include <stdlib.h>

#define MAX 128

int main(void)
{
	FILE *fp;
	char *ch1 = {"My name is "};
	char *ch2 = {"JING "};
	char *ch3 = {"HE\n"};

	char buf[MAX];

	if((fp = fopen("inputs.txt", "w")) == NULL)
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}

	fputs(ch1, fp);
	fputs(ch2, fp);
	fputs(ch3, fp);

	fclose(fp);

	if((fp = fopen("inputs.txt", "r+")) == NULL)
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}
	
	while(!feof(fp))
	{
		fgets(buf, MAX, fp);
		printf("%s", buf);
	}

	fclose(fp);
	
	return 0;
}
