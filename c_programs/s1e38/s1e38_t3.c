#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//ERROR: Cannot call the function when initializing static value;
	//The value stated by 'static' always exists during the program running.
	//--------------------------------------------------------------------
	//Usually it finished initialization process before the 'main' function.
	//However, the order of calling malloc function is after 'main' function.
	//---------------------------------------------------------------------
	//So from the concept, it is impossible that the value stated by 'static' does
	//initialization through call the function in <stdlib.h>.
	//---------------------------------------------------------------------
	//The situation of global varibles is the same!
	
/*
	static int *pi = (int *)malloc(sizeof(int));

	*pi = 520;

*/
	//Thus, for the static variables, it can avoid this problem through
	//adding a separate sentence in order to allocate memeory for the variable.
	static int *pi;
	pi = (int *)malloc(sizeof(int));

	//It needs to figure out the priority of the operator (Operator precedence)
	(*pi)++;
	(*pi)++;

	printf("*pi = %d\n", *pi);
	free(pi);
	return 0;
}
