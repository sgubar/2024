#include "tool.h"

int factorial(int n)
{
	int fact = 1;
	for (int i = 1; i <= n; ++i) {
		fact *= i;
	}
	return fact;
}

int exponent(int a, int b)
{
	int exp = 1;
	for (int i = 0; i < b; i++)
	{
		exp *= a;
	}

	if (a == 0)
	{
		exp = 0;
	}
	return exp;
}