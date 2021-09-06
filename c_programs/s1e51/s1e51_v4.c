#include <stdio.h>

union data
{
	int i;
	char ch;
	float f;
};

int main(void)
{
	union data a = {520};		//初始化第一个成员.
	union data b = a; 		//直接用一个共用体初始化另一个共用体.
	union data c = {.ch = 'J'};	// c99新特性 - 指定初始化成员.
	return 0;
}
