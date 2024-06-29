include <stdio.h>
include "tool.h"

int main(void)
{
	int a, b, c, q;

	a = enterNum('A');
	b = enterNum('B');
	c = enterNum('C');

	if (b < 0)
	{
		printf("The value of B must be greater than zero\n");
		return 1;
	}

	q = ((exponent(a, 2) + exponent(b, 2)) / (b + exponent(5, c))) + factorial(b);
	printf("Result: %d\n", q);

	return 0;
}
