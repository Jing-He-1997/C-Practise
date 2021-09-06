#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100

void push(double f);
double pop(void);
int getch(void);
void ungetch(int c);
int getop(char s[]);

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if(sp >= MAXVAL)
	{
		printf("错误：栈已满！\n");
	}
	else
	{
		val[sp++] = f;
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

#define BUFSIZE 100
#define NUMBER '0'

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
	{
		printf("错误：缓冲区已满！\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}

int getop(char s[])
{
	int i, c;

	while((s[0] = c =getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if(!isdigit(c) && c != '.')
	{
		return c;
	}

	i = 0;
	if(isdigit(c))
	{
		while(isdigit(s[++i] = c = getchar()))
			;
	}

	if(c == '.')
	{
		while(isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';

	if(c != EOF)
	{
		ungetch(c);
	}

	return NUMBER;
}

#define MAXOP 100

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	
	while((type = getop(s))!= EOF)
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
			if(op2 != 0)
			{
				push(pop() / op2);
			}
			else
			{
				printf("错误：除法溢出！\n");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("错误：未知指令！\n");
			break;
		}
	}
	return 0;
}
