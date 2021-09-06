#include <stdio.h>

#define HEIGHT 7
void print_Name(const char *letters[5][HEIGHT]);

//定义一个指针数组
const char *letters[6][HEIGHT]={
	{"##    ##",
	 "##    ##",
	 "##    ##",
	 "########",
	 "##    ##",
	 "##    ##",
	 "##    ##"},

	{"########",
	 "##      ",
	 "##      ",
	 "######  ",
	 "##      ",
	 "##      ",
	 "########"},

	{"  ####  ",
	 "   ##   ",
	 "   ##   ",
	 "   ##   ",
	 "   ##   ",
	 " # ##   ",
	 "  ##    "},

	{" #### ",
	 "  ##  ",
	 "  ##  ",
	 "  ##  ",
	 "  ##  ",
	 "  ##  ",
	 " #### "},

	{"##     ##",
	 "###    ##",
	 "## #   ##",
	 "##  #  ##",
	 "##   # ##",
	 "##    ###",
	 "##     ##"},

	{" ######",
	 "##    ##",
	 "##      ",
	 "##      ",
	 "##  ####",
	 "##    ##",
	 " ###### "}};

void print_Name(const char *letters[6][HEIGHT])
{
	int i, j;
	int gap;
	printf("请输入字母的间隔(空格数)：");
	scanf("%d",&gap);

	for(i = 0; i < HEIGHT ; i++)
	{
		for(j = 0; j < 6; j++)
		{
			printf("%s",letters[j][i]);
			int num = gap;
			while(num--)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main()
{
	print_Name(letters);
	return 0;
}
