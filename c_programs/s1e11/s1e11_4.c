#include <stdio.h>
#include "ssebtr1.h" //假装有这个方法 整蛊大王！

int main()
{
	int age, max_hbeat, i, BPM = 150;
	
	printf("请输入年龄：");
	scanf("%d",&age);

	max_hbeat = 220 - age;

	playSound(BPM);
	i = getHeartRate();

	if(i > max_hbeat)
	{
		printf("请马上停止跑步，否则会有生命危险...");
	}
	else if(i > max_hbeat * 0.85)
	{
		printf("请放慢脚步");
		BPM = BPM - 20;
		playSound(BPM); //这里不能直接输入BPM - 20
	}
	else if (i < max_hbeat * 0.75)
	{
		printf("请加快节奏");
		BPM = BPM + 20；
		playSound(BPM);
	}
	else
	{
	}

	return 0;
	
}
