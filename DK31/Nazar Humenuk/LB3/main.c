#include "tree.h"
#include <cs50.h>

int main(void) {
  Tree *Tras = fillTree();
  
  printTree(Tras);

  destroyTree(Tras);//видаляємо дерево
  return 0;
}