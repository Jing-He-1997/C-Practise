#include <stdio.h>

//代码局限性很强！！！！
void binary(char*, int, int);

void binary(char *array, int num, int count)
{
	if(num!=0)
	{
		array[count--] = num % 2 + '0';
		num /= 2; 
		binary(array, num, count);	
	}
	// 18 array[15] = '0' num = 9
	// 9 array[14] = '0' num = 4
	// 4 array[13] = '0' num = 2
	// 2 array[12] = '0' num = 1
	// 1 array[11] = '1' num = 0
}


int main(void)
{
	int count = 15;
	int num;
	printf("请输入一个整数：");
	scanf("%d",&num);
	
	char array[17] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','\0'};
	binary(array, num, count);
	printf("2进制数为：%s\n", array);

	return 0;
}
