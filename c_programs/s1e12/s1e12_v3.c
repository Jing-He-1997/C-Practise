#include <stdio.h>

//悬挂else bug
int main()
{
	char isFree, isRain;

	printf("是否有空(Y/N):");
	scanf("%c",&isFree);
	
	getchar();

	printf("是否下雨(Y/N):");
	scanf("%c",&isRain);

	if(isFree == 'Y')
		if(isRain == 'Y')
		printf("记得带伞哦！\n");
	else
	{
		printf("他没空 TT\n");
	} // 这里的else对应的是第二个if
	return 0;
}
