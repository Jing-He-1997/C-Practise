#include <stdio.h>

int main()
{
	char ch;
	int count = 0, count_a = 0, count_e = 0, count_i = 0, count_o = 0, count_u = 0;

	printf("请输入一个英文句子:");
	while((ch = getchar()) != '\n')  //getchar()的返回值是int
	{
		if(ch == 'a' || ch == 'A')
		{
			count_a++;
		}
		else if(ch == 'e' || ch == 'E')
		{
			count_e++;
		}
		else if(ch == 'i' || ch == 'I')
		{
			count_i++;
		}
		else if(ch == 'o' || ch == 'O')
		{
			count_o++;
		}
		else if(ch == 'u' || ch == 'U')
		{
			count_u++;
		}
		else{}
	}

	count = count_a + count_e + count_i + count_o + count_u;

	printf("你输入的句子中，包含元音字母%d个！\n",count);
	printf("其中：a(%d),e(%d),i(%d),o(%d),u(%d)\n",count_a,count_e,count_i,count_o,count_u);
	
	return 0;
}
