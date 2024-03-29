#include "tree.h"
#include <cs50.h>

int main(void) {
  Tree *Tras = fillTree();//створюємо та заповнюємо дерево
  
  printTree(Tras);//виводимо дерево

  destroyTree(Tras);//видаляємо дерево
  return 0;
}
