#include <stdio.h>
#include <stdlib.h>

#include "my_tree.h"

int main(void) {
	Tree *t = createTree();

	insertElement(t, 30);
	insertElement(t, 25);
	insertElement(t, 54);
	insertElement(t, 42);
	insertElement(t, 60);
	insertElement(t, 55);
	insertElement(t, 80);
	insertElement(t, 58);
	insertElement(t, 57);
	insertElement(t, 59);

	printTree(t);

	deleteElement(t, 54);

	printf("\n");
	printTree(t);


	destroyTree(t);

	return 0;
}
