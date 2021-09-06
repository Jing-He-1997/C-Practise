#include <stdio.h>
void print_H();
void print_E();
void print_J();
void print_I();
void print_N();
void print_G();

void print_H()
{
	printf("##    ##\n");
	printf("##    ##\n");
	printf("########\n");
	printf("##    ##\n");
	printf("##    ##\n");
	printf("\n");
}
void print_E()
{
	printf("######  \n");
	printf("##      \n");
	printf("####    \n");
	printf("##      \n");
	printf("######  \n");
	printf("\n");
}
void print_J()
{
	printf(" ###### \n");
	printf("   ##   \n");
	printf("   ##   \n");
	printf(" # ##   \n");
	printf("  ##    \n");
	printf("\n");
}
void print_I()
{
	printf("  ####  \n");
	printf("   ##   \n");
	printf("   ##   \n");
	printf("   ##   \n");
	printf("  ####  \n");
	printf("\n");
}
void print_N()
{
	printf("##     ## \n");
	printf("## #   ## \n");
	printf("##  #  ## \n");
	printf("##   # ## \n");
	printf("##     ## \n");
	printf("\n");
}
void print_G()
{
	printf(" ######## \n");
	printf("##      ##\n");
	printf("##        \n");
	printf("##     ###\n");
	printf("##      ##\n");
	printf(" ######## \n");
	printf("\n");
}

int main()
{
	print_H();
	print_E();
	print_J();
	print_I();
	print_N();
	print_G();
	return 0;
}
