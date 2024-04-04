#include "tree.h"
#include <stdio.h>

int main() {
  IntTree *tree = createIntTree();
  insertIntValueToTree(tree, 53); //рутовий елемент
  insertIntValueToTree(tree, 43);
  insertIntValueToTree(tree, 65);
  insertIntValueToTree(tree, 30);
  insertIntValueToTree(tree, 14);
  insertIntValueToTree(tree, 9);
  insertIntValueToTree(tree, 23);
  insertIntValueToTree(tree, 35);
  insertIntValueToTree(tree, 98);
  insertIntValueToTree(tree, 99);
  insertIntValueToTree(tree, 57);
  insertIntValueToTree(tree, 87);
  //обхід дерева є симетричним 
  
  printTree(tree);

IntTree *node43 = findNodeWithValue(tree, 14);
 if (NULL!=node43){
    printNode(node43);
   printf("\n");
   
 }else{
   printf("The node with a key not found\n ");
 }
  
  deleteNodeWithValue(tree, 30);
  printTree(tree);
  
  
  destroyIntTree(tree);

  // insert code here...
  printf("\nHello, World!\n");
  return 0;
}
