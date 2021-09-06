#include <stdio.h>
#include <time.h>

int main(void)
{
	//sun, mon, tue...这些为枚举常量;
	//枚举常量与宏定义类似,但不同于宏定义的是,枚举常量的值是int类型的;
	//默认情况下,枚举常量是从0开始定义(sun = 0);
	enum Week {sun, mon, tue, wed, thu, fri, sat};
	enum Week today; 	//today为枚举变量
	struct tm *p;
	time_t t;

	time(&t);
	p = localtime(&t);

	today = p->tm_wday;

	switch(today)
	{
		case mon:	
		case tue:	
		case wed:	
		case thu:	
		case fri:
			printf("Weekday...\n");
			break;
		case sat:
		case sun:
			printf("Weekend!\n");
			break;
		default:
			printf("ERROR!\n");
			break;
	}
	
	return 0;
}
