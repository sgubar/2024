#include <stdio.h>
#include <stdlib.h>

#include "my_tree.h"

int main(void) {
	Tree *t = NULL;

	VALTYPE inputBuffer;
	unsigned char choose = 0;

	while (1) {
		switch(choose) {
		case 0:
			printf("\n"
				   " 1: create list\n"
				   " 2: destroy list\n"
				   " 3: insert number to list\n"
				   " 4: delete number from list\n"
				   " 5: search number in list\n"
				   " 6: print list\n"
				   "99: exit\n"
				   "\n");
			break;

		case 1:
			t = requestTree();
			printf("Tree created!\n");
			break;

		case 2:
			destroyTree(t);
			t = NULL;
			printf("Tree destroyed!\n");
			break;

		case 3:
			printf(": ");
			scanf(VALFSTR, &inputBuffer);
			insertElement(t, inputBuffer);
			printf("Element inserted!\n");
			break;

		case 4:
			printf(": ");
			scanf(VALFSTR, &inputBuffer);
			deleteElement(t, inputBuffer);
			printf("Element deleted!\n");
			break;

		case 5:
			printf(": ");
			scanf(VALFSTR, &inputBuffer);
			TreeNode *n = searchElement(t, inputBuffer);
			if (n == NULL) {
				printf("Element not found!\n");
			} else {
				printf("Element found!\n");
			}
			break;

		case 6:
			printf("Tree: ");
			printTree(t);
			printf("\n");
			break;

		case 99:
			printf("Exiting...");
			exit(0);
			break;

		default:
			printf("Wrong argument!\n");
			break;
		}

		printf("? ");
		scanf("%hhd", &choose);
	}

	return 0;
}
