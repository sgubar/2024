#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int factorial (int n)
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
	return exp;
}

int main(void)
{
	int a, b, c, q;

	printf("Enter the integer value A: ");
	if (scanf("%d", &a) != 1)	//Перевірка чи не є це цифрою
	{
		printf("This is not a number");
		return -1;
	}

	printf("Enter a positive integer value B: ");
	if (scanf("%d", &b) != 1)	//Перевірка чи не є це цифрою
	{
		printf("This is not a number");
		return -2;
	}

	printf("Enter the integer value C: ");
	if (scanf("%d", &c) != 1)	//Перевірка чи не є це цифрою
	{
		printf("This is not a number");
		return -3;
	}


	if (b < 0)
	{
		printf("The value of B must be greater than zero\n");
		return 1;
	}

	q = ((exponent(a, 2) + exponent(b, 2)) / (b + exponent(5, c))) + factorial(b);
	printf("Result: %d\n", q);

	return 0;
}
