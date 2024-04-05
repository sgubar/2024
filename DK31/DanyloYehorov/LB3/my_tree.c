#include "my_tree.h"

#include <stdio.h>
#include <stdlib.h>

void destroyNode(TreeNode *currentNode);
signed char insertNode(TreeNode **current, VALTYPE num);
TreeNode **searchNode(TreeNode **current, VALTYPE num);
void printNode(TreeNode *node);

Tree *createTree(void) {
	Tree *result = (Tree*) malloc(sizeof(Tree));

	if (result != NULL) {
		result->root = NULL;
		result->count = 0;
	}

	return result;
}


void destroyTree(Tree *tree) {
	if (tree != NULL) {
		destroyNode(tree->root);

		free(tree);
	}
}


void destroyNode(TreeNode *currentNode) {
	if (currentNode != NULL) {
		destroyNode(currentNode->left);		// destroy left node
		destroyNode(currentNode->right);	// destroy right node

		free(currentNode);
	}
}


void insertElement(Tree *tree, VALTYPE num) {
	if (tree == NULL) {
		return;
	}

	tree->count += insertNode(&(tree->root), num);
}


signed char insertNode(TreeNode **current, VALTYPE num) {
	if (*current == NULL) {									// if current node void -> place number here
		*current = (TreeNode*) malloc(sizeof(TreeNode));

		if (*current != NULL) {
			(*current)->num = num;
			(*current)->left = NULL;
			(*current)->right = NULL;
			return 1;
		}

		return 0;
	}

	if (num < (*current)->num) {							// if number lesser then current number
		return insertNode( &((*current)->left), num);		// go left
	} else if (num > (*current)->num) {						// if number greater then current number
		return insertNode( &((*current)->right), num);		// go right
	}
	return 0;												// number already exist
}


void deleteElement(Tree *tree, VALTYPE num) {
	if (tree == NULL) {												// tree don't exist
		return;
	}

	TreeNode **currentPtr = searchNode(&(tree->root), num);			// save "connection" (tree.root | node.left | node.right)

	if (currentPtr == NULL) {
		return;
	}
	tree->count--;													// decrement counter

	TreeNode *current = *currentPtr;								// "current" - element whose value should be deleted

	if (current->left == NULL && current->right == NULL) {			// node is leaf
		*currentPtr = NULL;											// clean connection to this node
		free(current);												// destroy leaf
	} else if ((current->left != NULL) != (current->right != NULL)) {// one child, right XOR left
		*currentPtr = (current->right == NULL ? current->left : current->right); // save connection for correspondent branch
		free(current);												// destroy "intermediate" element
	} else if (current->left != NULL && current->right != NULL) {	// two children
		TreeNode **successorPtr = &(current->right);				// pointer to successor element

		// 1. find minimal (actually, most left) element in right branch
		while ((*successorPtr)->left != NULL) {						// is there more left element than current?
			successorPtr = &((*successorPtr)->left);				// save connection to left element
		}

		// 2. set current value to successor value
		current->num = (*successorPtr)->num;

		// 3. successors' parent left element -> right child of successor
		TreeNode *buf = *successorPtr; 							// save pointer to successor for later deletion
		*successorPtr = (*successorPtr)->right;					// replace connection with connection of new element
		free(buf);
	}
}

TreeNode* searchElement(Tree *tree, VALTYPE num) {
	if (tree == NULL) {
		return NULL;
	}

	TreeNode **res = searchNode(&(tree->root), num);				// get pointer to node
	return (res == NULL ? NULL : *res);								// return pointer to node or NULL if node doesn't exist
}


TreeNode **searchNode(TreeNode **current, VALTYPE num) {
	if ((*current) == NULL) {										// if node == NULL -> node with searched number doesn't exist
		return NULL;
	}

	if (num < (*current)->num) {									// if searched number lesser than number of current
		return searchNode(&((*current)->left), num);				// go to left branch
	} else if (num > (*current)->num) {								// if searched number greater than number of current
		return searchNode(&((*current)->right), num);				// go to right right
	} else {														// number == searched number
		return current;												// return pointer to node's pointer
	}
}


void printTree(Tree *tree) {
	if (tree != NULL) {
		printNode(tree->root);
	} else {
		printf("(NULL)");
	}
}

void printNode(TreeNode *node) {
	if (node != NULL) {
		printNode(node->left);
		printNode(node->right);
		printf(VALFSTR  " ", node->num);
	}
}

Tree *requestTree(void) {
	Tree *result = createTree();
	VALTYPE number;

	printf("Enter numbers separated by spaces and ending with a character that is not a number.\n");
	while (scanf(VALFSTR " ", &number) == 1) {
		insertElement(result, number);
	}
	while (getchar() != '\n');          							// clean the input buffer

	return result;
}
