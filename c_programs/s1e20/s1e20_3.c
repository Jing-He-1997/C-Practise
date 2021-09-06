#include <stdio.h>
#include <string.h>
int main()
{
	int num;
	char ch;
	printf("一共要输入的句子数量：");
	scanf("%d",&num);
	int a[num];
	
	int max = 0, min = 0,temp;
	char str[num][100];
	getchar();

	for(int i = 0; i < num; i++)
	{
		int count = 0;
		int j = 0;
		printf("请输入第%d句话：",i + 1);
		
		while((ch = getchar())!= '\n')
		{
			str[i][j]= ch;
			j++;
			count++;
		}
		str[i][j]='\0';
		a[i] = count;
	}

	//打印每一句话
	printf("您输入了下面的%d句话：\n",num);
	for(int k = 0;k < num; k++ )
	{
			printf("%s\n",str[k]);
	}
	
	//比较长度
	for(int i1 = 0; i1 < num; i1++)
	{
		temp = strlen(str[i1]);
		//如果比较表达式为真，min = i1，为假，min = min
		min = temp < strlen(str[min])? i1:min;
		//如果比较表达式为真，max = i1，为假，max = max
		max = temp > strlen(str[max])? i1:max;
	}

	printf("最长的是%s\n",str[max]);
	printf("最短的是%s\n",str[min]);
	
	
	return 0;
}
