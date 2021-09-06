#include <stdio.h>

#define MAX 1024
int main()
{
	char str[MAX];
	char *p = str;
	char ch;
	int length = 0;

	printf("请输入一个字符串：");
	//gets()和fgets()的区别:
	//char *gets(char *buffer);
	//gets() - 从键盘上输入字符，直到接受到换行符号或EOF时为止，并将读取的结果存放在buffer指针
	//所指向的字符数组中。读取的换行符被转换为NULL，做为字符数组的最后一个字符，来结束字符串.
	//Warning: gets没有指定输入字符大小，所以会无限读取，从而发生内存越界！
	//=======================================================================================
	//char *fgets(char *s, int n, FILE *stream);
	//fgets() - 从文件指针stream中读取字符，存到以s为起始地址的空间里，直到读完N-1个字符，或者读完一行
	//fgets最多只能读n-1个字符，读入结束后，系统将自动在最后加入'\0',并以str作为函数值返回
	fgets(p, MAX, stdin);//MAX包括'\0'，stdin指向的是标准输入流

	while(1)
	{
		//I love FishC.com!

		ch = *p++;//先取出p中的值，再指向下一个对象,相当于*(p++)
		
		if(ch == '\0')
		{
			break;
		}
		else
		{
			length++;
		}	
	}

	printf("一共有多少个字符：%d\n",length - 1);//这里减1的原因是因为在输入字符串的							//时候标准输入流还接收了一个换行符\n


	return 0;

}


