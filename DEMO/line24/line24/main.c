//
//  main.c
//  line24
//
//  Created by Slava Gubar on 23.02.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "line.h"

int main(int argc, const char * argv[]) {
	Point A = {5, 5};
	Point B = {6, 7};

//	Point *A = createPoint(5, 5);
//	Point *B = createPoint(6, 7);
//	Point *C = createPoint(10, 10);

	Line *AB = createLine(&A, &B);
	Line *CD = createLine(&A, &B);

	Line *array[2] = {AB, CD};
	Line **dyn = malloc(sizeof(Line *) * 10);
	dyn[0] = AB;
	dyn[1] = CD;

	CD->A->x = 0;
	CD->A->y = 0;

	printLine(AB);
	printf("\n");
	printLine(CD);
	printf("\n");

//	destroyPoint(A);
//	destroyPoint(B);
	destroyLine(AB);
	destroyLine(CD);
	free(dyn);
	return 0;
}
