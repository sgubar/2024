#define _CRT_SECURE_NO_WARNINGS

#include "dk_tool.h"
#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int col, row;
	printf("Enter the number of rows in both matrices (Max 20): ");
	if (scanf("%d", &row) == 0)	//Перевірка чи не є це цифрою
	{
		printf("This is not a number");
		return -1;
	}
	
	printf("Enter the number of columns in both matrices (Max 20): ");
	if (scanf("%d", &col) == 0)
	{
		printf("This is not a number");
		return -1;
	}

	if (row > 20 || col > 20)
	{
		printf("The matrix is too large. The maximum value is 20");
		return 1;
	}

	printf("Enter first matrix\n");
	int** mat1 = enter_matrix(NULL, col, row, 1);
	printf("Enter second matrix\n");
	int** mat2 = enter_matrix(NULL, col, row, 2);

	matrix_plus(mat1, mat2, col, row);

	free_matrix(mat1, row);
	free_matrix(mat2, row);
	return 0;
}