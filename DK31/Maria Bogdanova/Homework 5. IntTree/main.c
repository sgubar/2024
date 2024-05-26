#include "tree.h"
#include <stdio.h>

int main() {
  IntTree *tree = createIntTree();
  insertIntValueToTree(tree, 88); //рутовий елемент
  insertIntValueToTree(tree, 56);
  insertIntValueToTree(tree, 8);
  insertIntValueToTree(tree, 11);
  insertIntValueToTree(tree, 67);
  insertIntValueToTree(tree, 100);
  insertIntValueToTree(tree, 5);
  insertIntValueToTree(tree, 35);
  insertIntValueToTree(tree, 98);
  insertIntValueToTree(tree, 89);
  insertIntValueToTree(tree, 34);
  insertIntValueToTree(tree, 77);
  //обхід дерева є симетричним 
  
  printTree(tree);

IntTree *node43 = findNodeWithValue(tree, 8);
 if (NULL!=node43){
    printNode(node43);
   printf("\n");
   
 }else{
   printf("The node with a key not found\n ");
 }
  
  deleteNodeWithValue(tree, 53);
  printTree(tree);
  
  
  destroyIntTree(tree);

  printf("\nHello, World!\n");
  return 0;
}
