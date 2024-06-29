#define _CRT_SECURE_NO_WARNINGS
#include "tool.h"

#include <ctype.h>
#include <stdio.h>

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

int enterNum(char lett)
{
	int num;
	printf("Enter the integer value %c: ", lett);

	//Перевірка чи не є це цифрою
	if (scanf("%d", &num) != 1)
	{
		printf("This is not a number");
		return -1;
	}

	return num;
}