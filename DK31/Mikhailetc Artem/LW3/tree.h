#ifndef TREE_H
#define TREE_H

typedef double VALTYPE;

typedef struct TreeNode {
    VALTYPE num;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct Tree {
    TreeNode *root;
    int count;
} Tree;

Tree *createTree(void);
void destroyTree(Tree *tree);
void insertElement(Tree *tree, VALTYPE num);
void deleteElement(Tree *tree, VALTYPE num);
TreeNode* searchElement(Tree *tree, VALTYPE num);
void printTree(Tree *tree);

#endif // TREE_H
