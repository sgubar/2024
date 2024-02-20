#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int** enter_matrix(int **matArr, int col, int row, int k)
{
	matArr = create_sapce(matArr, col, row);
	for (int i = 0; i < row; i++)
	{
		printf("Enter the value of the %d row: \n", i + 1);
		for (int j = 0; j < col; j++)
		{
			printf("Enter the integer values of the %d column: ", j + 1);
			if (scanf("%d", &matArr[i][j]) != 1)
			{
				printf("This is not a number");
				free_matrix(matArr, i);
				return NULL;
			}
		}
	}
	printf("Your %d matrix:\n", k);
	print_matrix(matArr, col, row);
	return matArr;
}

void print_matrix(int** mat, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void free_matrix(int** mat, int row)
{
	for (int i = 0; i < row; i++)
	{
		free(mat[i]);
	}

	free(mat);
}

void matrix_plus(int** mat1, int** mat2, int col, int row)
{
	int** matPlus = 0;
	matPlus = create_sapce(matPlus, col, row);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matPlus[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	printf("First plus second matrix: \n");
	print_matrix(matPlus, col, row);
	free_matrix(matPlus, row);
}

int** create_sapce(int** arr, int col, int row)
{
	arr = (int**)malloc(sizeof(int*) * row);
	if (arr == NULL)
	{
		printf("Memory allocation failed");
		return NULL;
	}

	for (int i = 0; i < row; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * col);
		if (arr[i] == NULL)
		{
			printf("Memory allocation failed");
			return NULL;
		}
	}
	return arr;
}