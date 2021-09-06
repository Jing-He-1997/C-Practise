#include <stdio.h>

#define PI 3.14159
#define S(r) PI*r*r
#define C(r) 2*r*PI

int main()
{
	int r = 5;
	double s = S(r);
	double c = C(r);

	printf("半径为%d的圆，面积是%.2f,周长是：%.2f\n", r, s, c);

	return 0;
}
