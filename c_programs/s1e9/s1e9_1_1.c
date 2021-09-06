#include <stdio.h>
#include <math.h>

int main()
{
	float price,area,yir,mir;
	float interest,loan;
	float ave_repay, down_payment;
	float total_price, total_repay;
	int ratio, time;

	printf("单价：");
	scanf("%f",&price);
	printf("面积：");
	scanf("%f",&area);
	printf("按揭成数：");
	scanf("%d",&ratio);
	printf("按揭年数：");
	scanf("%d",&time);
	printf("年利率：");
	scanf("%f",&yir);

	mir = yir/100/12;
	time = time*12;
	total_price = price * area;
	loan = total_price * ratio / 10;
	ave_repay= loan*mir*pow((1+mir),time) / (pow((1+mir),time)-1);
	interest = ave_repay *time -loan;
	total_repay = loan + interest;
	down_payment = total_price * (1-(float)ratio / 10);

	printf("%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n",total_price, down_payment, loan, total_repay, interest, ave_repay);

	return 0;
}
