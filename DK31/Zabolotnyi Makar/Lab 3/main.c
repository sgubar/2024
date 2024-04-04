#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[]) {
  printf("Hello, World!\n");
  // create a tree
  DoubleTree *tree = createDoubleTree();
  double value;
  char choice;
  // insert some values
  do{
    printf("Enter a double value: ");
    scanf("%lf", &value);
    insertDoubleValueToTree(tree, value);
    printf("Do you want to continue? (enter y or n): ");
    scanf(" %c", &choice);
    
  }while(choice == 'Y' || choice == 'y'|| choice == 'n'|| choice == 'N');
  // print the tree
  printf("-The tree is:\n");
  printTree(tree);
  // find a value
  do{
    printf("Enter a value which you want find: ");
    scanf("%lf", &value);
    DoubleNode *node = findNodeWithValue(tree, value);
    if (NULL != node){
      printf("The value is found: %.1f\n", node->value);
    }
    else {printf("The value isn't found\n");}
    printf("Do you want to continue? (enter y or n): ");
    scanf(" %c", &choice);

  }while(choice == 'Y' || choice == 'y'|| choice == 'n'|| choice == 'N');
  // delete a value
  do{
    printf("Enter a value to delete: ");
    scanf("%lf", &value);
    deleteNodeWithValue(tree, value);
    printf("Do you want to continue? (enter y or n): ");
    scanf(" %c", &choice);
    
  }while(choice == 'Y' || choice == 'y'|| choice == 'n'|| choice == 'N');
  // print the tree
  printf("-After deleting the value\n");
  printTree(tree);
  
  printf("Good Bye, World!\n");
  // destroy the tree
  destroyDoubleTree(tree);
  return 0;
}
