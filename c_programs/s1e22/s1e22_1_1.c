#include <stdio.h>

#define MAX 1024
int main()
{
	char str[MAX];
	char *p = str;
	char ch;
	int length = 0;

	printf("请输入一个字符串：");
	fgets(p, MAX, stdin);//MAX包括'\0'，stdin指向的是标准输入流

	while(1)
	{
		//I love FishC.com!

		ch = *p++;//先取出p中的值，再指向下一个对象,相当于*(p++)
		
		if(ch == '\0')
		{
			break;
		}
		else if((int)ch < 0)//表示汉字，汉字在c中占3个字节
		{
			p+= 2;//指向下一个对象，需要在移动了一个字节的前提下移动两个字节
		}
		length++;	
	}

	printf("一共有多少个字符：%d\n",length - 1);//这里减1的原因是因为在输入字符串的							//时候标准输入流还接收了一个换行符\n


	return 0;

}


