#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct __tagNode
{
  double value;
  struct __tagNode *leftChild;
  struct __tagNode *rightChild;
} DoubleNode;

typedef struct __tagTree
{
  DoubleNode *root;
  int count;
} DoubleTree;

// interface
DoubleTree *createDoubleTree();
void destroyDoubleTree(DoubleTree *aTree);

void insertDoubleValueToTree(DoubleTree *aTree, double aValue);
DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue);
void deleteNodeWithValue(DoubleTree *aTree, double aValue);

void mergeTrees(DoubleTree *aTreeDst, DoubleTree *aTreeSrc);

void printTree(DoubleTree *aTree);
void printNode(DoubleNode *aNode);
int countNodesWithTree(DoubleTree *aTree);

#endif 
