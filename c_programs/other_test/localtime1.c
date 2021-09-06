#include <stdio.h>
#include <time.h>

#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6

int main(void)
{
	struct tm *p;
	time_t t;

	time(&t);		//获取当前的秒数
	p = localtime(&t);	//将获取的time_t(无符号整型)的指针传入localtime中；
				//传进去后返回的值是一个指向tm结构体的指针。

	switch(p->tm_wday)
	{
		case MON:
		case TUE:
		case WED:
		case THU:
		case FRI:
			printf("干活! T T\n");
			break;
		case SAT:
		case SUN:
			printf("放假! ^ ^\n");
		default:
			printf("ERROR!\n");
	}
	
	printf("现在的时间是%d/%d/%d - %d:%d:%d\n", 1900+ p->tm_year, 1+p->tm_mon, p->tm_mday, 
	p->tm_hour, p->tm_min, p->tm_sec);

	return 0;
}
