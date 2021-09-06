#include <stdio.h>
#include <string.h>

#define HEIGHT 7

const char *letters[]={
"\
########@\
##      @\
##      @\
######  @\
##      @\
##      @\
##      @\
",
"\
####@\
 ## @\
 ## @\
 ## @\
 ## @\
 ## @\
####@\
",
"\
 ###### @\
##    ##@\
##      @\
 ###### @\
      ##@\
##    ##@\
 ###### @\
",
"\
##     ##@\
##     ##@\
##     ##@\
#########@\
##     ##@\
##     ##@\
##     ##@\
",
"\
 ###### @\
##    ##@\
##      @\
##      @\
##      @\
##    ##@\
 ###### @\
"
};

int main()
{
	int i, j;
	int gap;
	printf("请输入字母的间隔(空格数):");
	scanf("%d",&gap);

	for(i = 0; i < HEIGHT; i++)
	{
		for(j = 0; j < 5; j++)
		{	//k用来迭代每一行的‘#’
			int k =0;
			//计算出该字母每一行有多少个字符（因为每一个字母每一行的字符数相等）
			int len = strlen(letters[j]) / HEIGHT;
			//计算当前打印第几行
			int line = i * len;
			
			//'@'标志着该行结束
			while(letters[j][line+k]!= '@')
			{
				putchar(letters[j][line + k]);
				k++;
			}

			//打印字母间的间隔(空格)
			int temp = gap;
			while(temp--)
			{
				putchar(' ');
			}
		}
		putchar('\n');
	}
	
	return 0;
}


