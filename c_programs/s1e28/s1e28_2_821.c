#include <stdio.h>
#include <string.h>

#define HEIGHT 7
char *letters[] = {
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
#########@\
##       @\
##       @\
######   @\
##       @\
##       @\
#########@\
",
"\
  ###### @\
    ##   @\
    ##   @\
    ##   @\
    ##   @\
  # ##   @\
   ##    @\
",
"\
 #### @\
  ##  @\
  ##  @\
  ##  @\
  ##  @\
  ##  @\
 #### @\
",
"\
##     ##@\
###    ##@\
## #   ##@\
##  #  ##@\
##   # ##@\
##    ###@\
##     ##@\
",
"\
  ##### @\
##    ##@\
##      @\
##      @\
##      @\
##   ###@\
 #######@\
"
};

int main(void)
{
	int i, j;
	int gap;
	int k, len, line, temp;

	printf("请输入字母的间隔(空格数):");
	scanf("%d", &gap);

	for(i = 0 ; i < HEIGHT; i++)
	{
		for(j = 0; j < 6; j++)
		{
			k = 0;
			len = strlen(letters[j]) / HEIGHT;
			line = i * len;

			while (letters[j][line+k] != '@')
			{
				putchar(letters[j][line+k]);
				k++;
			}

			//打印空格
			temp = gap;
			while(temp--)
			{
				putchar(' ');
			}	
		}
		putchar('\n');
	}
	return 0;
}
