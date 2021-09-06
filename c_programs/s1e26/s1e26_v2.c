#include <stdio.h>

int main()
{
	char *cBook[]={
		"《C语言程序设计》",
		"《C专家编程》",
		"《C和指针》",
		"《C陷阱和缺陷》",
		"《C Prmier Plus》",
		"《带你学C带你飞》"};

	char *(*pp)[6] = &cBook;
	
	
	char **byFishC = &cBook[5];//cBook[5]是字符串（指向字符的指针），&cBook[5]是指向字符指针的					//指针。

	char **myLove[4];

	myLove[0] = &cBook[0];
	myLove[1] = &cBook[1];
	myLove[2] = &cBook[2];
	myLove[3] = &cBook[3];

	//汉字占3个字节 并且都是负数
	char chinese[3];
	chinese[0] = *(*byFishC + 3);
	chinese[1] = *(*byFishC + 4);
	chinese[2] = *(*byFishC + 5);

	printf("C语言书籍中第6本是 %s\n",*(*pp + 5));
	printf("出自FishC的书是 %s\n",*byFishC);// 因为打印的是字符串，所以只需要取字符串地址就ok
	printf("出自FishC的书第一个名字是 %s\n", chinese);
	printf("我最爱的第1本是 %s\n",*myLove[0]);
	printf("我最爱的第2本是 %s\n",*myLove[1]);
	printf("我最爱的第3本是 %s\n",*myLove[2]);
	printf("我最爱的第4本是 %s\n",*myLove[3]);

	return 0;
}
