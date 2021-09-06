#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 64
int main(void)
{
	FILE *fp;
	struct tm *p;
	time_t t;
	char buf[MAX];

	time(&t);
	p = localtime(&t);

	if((fp = fopen("timerecord.txt", "w")) == NULL)
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "%d-%d-%d", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday);

	fclose(fp);

	int year, mon, day;

	if((fp = fopen("timerecord.txt", "r")) == NULL)
	{
		printf("文件打开失败!\n");
		exit(EXIT_FAILURE);
	}
	
	fscanf(fp, "%d-%d-%d", &year, &mon, &day);
	printf("%d-%d-%d\n", year, mon, day);

	fclose(fp);
	return 0;
}
