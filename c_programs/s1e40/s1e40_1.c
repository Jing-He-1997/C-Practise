#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100 	//栈val的最大深度

void push(double); 	//将f压入到值栈中
double pop(void); 	//弹出并返回栈顶的值
int getch(void);	//从输入缓冲区取出一个字符
void ungetch(int);	//将字符送回缓冲区中
int getop(char s[]);	//从用户的输入中获取一个操作符或者操作数

int sp = 0;		//栈指针，指向下一个空闲位置
double val[MAXVAL];	//值栈

void push(double f)
{
	if(sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("错误：栈已满！\n");
	}
}

double pop(void)
{
	if(sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("错误：栈已空！\n");
		return 0.0;
	}
}

#define BUFSIZE 100	//缓冲区的最大尺寸
#define NUMBER '0'	//只是一个标志而已，表示获取到一个数值

char buf[BUFSIZE];	//缓冲区
int bufp = 0;		//缓冲区指针，指向下一个空闲位置

int getch(void)
{
	
	//从标准输入流获得一个字符
	//如果buf缓冲区有存在字符，先从buf中获取
	return (bufp > 0)? buf[--bufp] : getchar();
}

//ungetch() 的作用是实现“反读”，即将最后读取的一个字符放回缓冲区中；
//由于每次调用getch()函数，都是先读取再判断，如果判断该字符并非操作数的组成部分(操作符或空格)，则调用ungetch()函数将其放回缓冲区
void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("错误：缓冲区已满！\n");
	else
		buf[bufp++] = c;
}

int getop(char s[])
{
	int i, c;
	
	//因为用户的输入是通过空格或制表符作为分隔符的，所以需要先跳过他们
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	//不是数字，直接将其返回
	if(!isdigit(c) && c != '.')
		return c;

	//收集整数部分
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;

	//收集小数部分
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';

	//如果上述的内容都不是，将c放回缓冲区中;
	if(c != EOF)
		ungetch(c);

	return NUMBER;	//占一个位置 
}

#define MAXOP 100

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() / op2);
			else
				printf("Error: zero divide overflow");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("Error: unknown command %s\n", s);
			break;
		}
	}
	
	return 0;
}
