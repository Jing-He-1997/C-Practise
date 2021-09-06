#include <stdio.h>

int main()
{
	int a = 1, b = 2, c = 3, d = 4;
	
	printf("%d\n", (a+(b*c)) - 4 == 3);
	printf("%d\n",a + b && c / d);
	printf("%d\n",a = b && c - d);
	printf("%d\n",'a'+ 'b'<= 'c'||a / b + d % c);
	printf("%d\n",!!a + !b + c - a -c);
	printf("%d\n",a = b - c ||a % b && c / d);

	return 0;
}
