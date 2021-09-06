#include <stdio.h>
#include <math.h>

int main()
{
	int year, radio;
	float price, space, rate, res1, res2, res3, res4, res5, res6;

	printf("请输入单价（元/平方）：");
	scanf("%f",&price);
	printf("请输入面积：");
	scanf("%f",&space);
	printf("请输入按揭成数：");
	scanf("%d",&radio);
	printf("请输入按揭年数：");
	scanf("%d",&year);
	printf("请输入当前基准年利率：");
	scanf("%f",&rate);

	res1 = price * space;
	res3 = res1 * radio / 10;
	res2 = res1 - res3;
	res6 = res3 * (rate/100/12 * pow(1 + rate/100/12, 12*year))/(pow(1 + rate/100/12,12*year)-1);
	res4 = res6 * 12 * year;
	res5 = res4 - res3;

	printf("============计算中..================\n");

	printf("房款总额：%.2f\n", res1);
	printf("首期付款：%.2f\n", res2);
	printf("贷款总额：%.2f\n", res3);
	printf("还款总额：%.2f\n", res4);
	printf("支付利息：%.2f\n", res5);
	printf("月均还款：%.2f\n", res6);

	return 0;
}
