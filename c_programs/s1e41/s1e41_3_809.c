#include <stdio.h>

#define ARGUMENTS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, ...) A11
#define COUNTS(...) ARGUMENTS(JING, ##__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define PRINT_COUNTS(...) printf("COUNTS(%s)有 %d 个参数\n", # __VA_ARGS__, COUNTS(__VA_ARGS__))

int main(void)
{
	PRINT_COUNTS();
	PRINT_COUNTS(1, 2, 3);
	PRINT_COUNTS("Apple", "Banana", "Cat", "Dog");
	return 0;
}
