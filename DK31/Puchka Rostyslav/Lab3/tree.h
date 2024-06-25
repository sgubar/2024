#ifndef TREE_H
#define TREE_H

#include <stdio.h>

struct tagCharNode {
  char value;
  struct tagCharNode *leftChild;
  struct tagCharNode *rightChild;
};
typedef struct tagCharNode CharNode;

struct tagCharTree {
  CharNode *root;
  int count;
};
typedef struct tagCharTree CharTree;

CharTree *createCharTree();
void destroyCharTree(CharTree *tree);

void insertCharValueToTree(CharTree *tree, char value);
void deleteNodeWithValue(CharTree *tree, char value);

void printTree(CharTree *aTree);
void printNode(CharNode *aNode);

#endif
