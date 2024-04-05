#ifndef MY_TREE_H_
#define MY_TREE_H_

#include <stddef.h>


#define VALTYPE float
#define VALFSTR	"%f"


typedef struct tagTreeNode {
	VALTYPE num;

	struct tagTreeNode *left;
	struct tagTreeNode *right;
} TreeNode;

typedef struct tagTree {
	struct tagTreeNode *root;
	size_t count;
} Tree;


Tree *createTree(void);
void destroyTree(Tree *tree);

void insertElement(Tree *tree, VALTYPE num);
void deleteElement(Tree *tree, VALTYPE num);

TreeNode* searchElement(Tree *tree, VALTYPE num);

void printTree(Tree *tree);
Tree *requestTree(void);

#endif /* MY_TREE_H_ */
