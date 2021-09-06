#include <stdio.h>
#include <string.h>
#include "md5.h"

#define MAX 1024

void md5_encap(unsigned char*, unsigned char*);//封装md5加密
void salt(unsigned char*, unsigned char*);//加盐操作

void md5_encap(unsigned char* str1, unsigned char* str2)
{
	MD5_CTX md5;
	// 初始化
	MD5Init(&md5);
	// 传入明文字符的字符串和长度
	MD5Update(&md5, str2, strlen((char*) str2));
	// 得到加密后的字符串
	MD5Final(&md5, str1);
}

void salt(unsigned char *str1, unsigned char *str2)
{
	int i, j;

	for(int i = 4, j = 0; i < 12; i++, j++)
	{
		//以16进制的形式将str2[i]中的值写入str1中，每次写完后str1向右移两个单位
		snprintf(str1 + 2*j, 16, "%02x", str2[i]);
	}
}

int main()
{
	unsigned char src[MAX];
	unsigned char mix[MAX + 16];
	unsigned char dest[16];//用来存放md5加密和加盐后md5加密的密码
	unsigned char dest1[16];//用来存放md5加密后中间16位数

	printf("请输入密码：");
	scanf("%s",src);

	printf("您输入的密码是：%s\n", src);
	//printf("stelen(str2) = %d\n", strlen((char *)str2));

	md5_encap(dest, src);

	printf("加密后的密码是：");
	for(int i = 0; i < 16; i++)
	{
		printf("%02x", dest[i]);
	}
	putchar('\n');

	salt(dest1, dest);
	strncpy(mix, src, strlen(src));
	strncat(mix, dest1, 16);
	mix[strlen(src) + 16 + 1] = '\0';

	printf("加盐后的密码是：%s\n", mix);

	printf("加盐后加密的密码是：");
	md5_encap(dest, mix);
	for(int i = 0; i < 16; i++)
	{
		printf("%02x", dest[i]);
	}
	putchar('\n');
	
	return 0;
}

