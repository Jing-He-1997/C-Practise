#include <stdio.h>
#include <string.h>
#include "md5.h"

#define MAX 1024
MD5_CTX md5;

void MD5_Encap(unsigned char*, unsigned char*);
void salt(unsigned char*, unsigned char*);

void MD5_Encap(unsigned char *str1, unsigned char *str2)
{
	int i;

	//初始化
	MD5Init(&md5);
	//传入明文字符串以及长度
	MD5Update(&md5, str2, strlen((char *)str2));
	//得到加密后的字符
	MD5Final(&md5, str1);
}

void salt(unsigned char *mix, unsigned char *src)
{
	unsigned char temp1[16]; //存储原始数据第一次计算MD5的值
	unsigned char temp2[16]; //存储temp1中间16位为字符串

	int i, j, length;

	MD5_Encap(temp1, src);

	for(i = 4, j = 0; i < 12; i++, j++)
	{
		//一个temp1字符占两个16进制位
		//temp2 + 2*j （例如j = 0时 temp1[4]中的值放入temp2[0]和temp[1]中）	
		snprintf(temp2 + 2*j, 16, "%02x", temp1[i]);	
	}

	length = strlen(src);

	strncpy(mix, src, length - 1);//fgets把'\n'也加进去了，所以length - 1
	strncat(mix, temp2, 16);

	mix[length + 15] = '\0';	
}

int main()
{
	int i;
	unsigned char src[MAX];
	unsigned char mix[MAX + 16];
	unsigned char dest[16];

	printf("请输入密码：");
	fgets(src, MAX, stdin);

	printf("您的密码是：%s", src);
	
	salt(mix, src);
	printf("加盐后的密码是：%s\n", mix);

	MD5_Encap(dest, mix);
	
	printf("加密后的密码是：");
	for(i = 0; i < 16; i++)
	{
		printf("%02x",dest[i]);
	}

	putchar('\n');

	return 0;
}
