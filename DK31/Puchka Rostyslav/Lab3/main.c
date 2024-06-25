#include "tree.h"
#include <stdio.h>

void fillTree(CharTree *tree);
void trimTree(CharTree *tree);

int main(void) {
  CharTree *tree = createCharTree();
  printf("Empty tree: ");
  printTree(tree);
  printf("\n");

  fillTree(tree);
  printf("Created tree: ");
  printTree(tree);
  printf("\n\n");

  trimTree(tree);
  printf("Trimed tree: ");
  printTree(tree);
  printf("\n");

  destroyCharTree(tree);
  return 0;
}

void fillTree(CharTree *tree) {
  int buff;

  printf("Type seqence of chars that you want add to tree: ");

  buff = getchar();
  while ('\n' != buff) {
    insertCharValueToTree(tree, (char)buff);

    buff = getchar();
  }
}

void trimTree(CharTree *tree) {
  int buff;

  printf("Type seqence of chars that you want delete from tree: ");

  buff = getchar();
  while ('\n' != buff) {
    deleteNodeWithValue(tree, (char)buff);

    buff = getchar();
  }
}
