#include <stdio.h>
#include <string.h>

#define MAX 1024

void reverse(char*, char*, int);//将字符串中的每一个字符逆向存放

void reverse(char *array, char *array1, int n)
{
	if(n == strlen(array))
	{
		array1[n-1] = '\0';//先确定字符串输出的终止位置
	}
	//4-4,4-2 4-3,3-2 4-2,2-2
	array1[strlen(array)- n] = array[n - 2];//n - 2是因为要把'\0'和'\n'去掉

	if(n - 2 > 0)//去掉'\0'和'\n' 并且进行递归
	{
		reverse(array, array1, --n);
	}

}

int main(void)
{
	int n = 0;
	char ch;
	char array[MAX];
	char array1[MAX];
	printf("请输入一个以感叹号结尾的英文句子：");
	while((array[n] = getchar())!='\n')
	{
		n++;
	}
	array[++n]='\0';
	
	reverse(array, array1, n);

	printf("输出的字节长度为(包括0):%d\n", strlen(array));

	printf("反向输出：%s\n",array1);
	return 0;
}
