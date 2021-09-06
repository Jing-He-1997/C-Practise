#include <stdio.h>
#include <string.h>
#include "md5.h"

#define MAX 1024
MD5_CTX md5;

void MD5_Encap(unsigned char*, unsigned char*);

void MD5_Encap(unsigned char *str1, unsigned char *str2)
{
	int i;

	//初始化
	MD5Init(&md5);
	//传入明文字符串以及长度
	MD5Update(&md5, str2, strlen((char *)str2));
	//得到加密后的字符
	MD5Final(&md5, str1);
	printf("您的密码是：%s\n", str2);//因为fgets中也把'\n'放了进去
	printf("加密后的密码是：");
	for(i = 0; i< 16; i++)
	{
		printf("%02x", str1[i]);
	}
	putchar('\n');
}
int main()
{
	char ch;
	unsigned char encrypt[MAX];
	unsigned char decrypt[16];

	printf("请输入密码：");
	scanf("%s",encrypt);

	MD5_Encap(decrypt, encrypt);

	return 0;	
}
