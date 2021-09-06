#include <stdio.h>

#define Tomato 3.7
#define Kale 7
#define Celery 1.3
#define WaterSpinach 8
#define Onion 2.4
#define Cole 9
#define Cucumber 6.3
#define WhiteRadish 0.5

int main()
{
	double a,b,c;
	a = 1*Tomato + 0.5*WaterSpinach + 0.5*Cole;
	b = 1.5*Celery + 0.25*Onion + 2.5*Cucumber;
	c = 5*Cucumber + 10*WhiteRadish;

	printf("小明需要支付%.2f元\n", a);
	printf("小红需要支付%.2f元\n", b);
	printf("我需要支付%.2f元\n", c);

	return 0;
}
