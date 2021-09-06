#include <stdio.h>

#define BEGIN {
#define END }
#define IF if(
#define THEN ){
#define FI ;}
#define ELSE }else{
#define INT int

INT main()
BEGIN
	INT i;
	printf("请输入你的年龄：");
	scanf("%d",&i);

	IF i< 18 
	THEN
	printf("您不可以使用这个程序！！\n");
	ELSE
	printf("您可以使用这个程序！\n");
	FI

	return 0;
END

