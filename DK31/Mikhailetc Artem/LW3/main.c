#include "tree.h"
#include <stdio.h>

int main() {
  DoubleTree *tree = createDoubleTree();
  insertDoubleValueToTree(tree, 53.0); // Root element
  insertDoubleValueToTree(tree, 43.0);
  insertDoubleValueToTree(tree, 65.0);
  insertDoubleValueToTree(tree, 30.0);
  insertDoubleValueToTree(tree, 14.0);
  insertDoubleValueToTree(tree, 9.0);
  insertDoubleValueToTree(tree, 23.0);
  insertDoubleValueToTree(tree, 35.0);
  insertDoubleValueToTree(tree, 98.0);
  insertDoubleValueToTree(tree, 99.0);
  insertDoubleValueToTree(tree, 57.0);
  insertDoubleValueToTree(tree, 87.0);

  printTree(tree);

  DoubleNode *node = findNodeWithValue(tree, 14.0);
  if (NULL != node){
    printNode(node);
    printf("\n");
  } else {
    printf("The node with the key not found\n");
  }

  deleteNodeWithValue(tree, 30.0);
  printTree(tree);

  destroyDoubleTree(tree);

  printf("\nHello, World!\n");
  return 0;
}
