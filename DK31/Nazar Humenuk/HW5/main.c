#include "tree.h"
#include <cs50.h>

int main(void) {
  Tree *tree = createTree();//створюємо дерево
  char value = 9;
  insert(tree, value);//вводимо ементи в дерево
  value = 93;
  insert(tree, value);
  value = 4;
  insert(tree, value);
  value = 25;
  insert(tree, value);
  value = 23;
  insert(tree, value);
  value = 0;
  insert(tree, value);
  value = 5;
  insert(tree, value);
  
  printTree(tree);//виводимо дерево
  printf("\n");
  destroyElementByValue(tree, 93);// видаляємо елмент за значенням з дерева
  printTree(tree);//виводимо дерево
  printf("\n");
  
  Node *node = findElementByValue(tree, 4);//отримуємо елемент за значенням з дерева
  
  printNode(node);//виводимо ноду та всі наступні привязані ноди
  
  destroyTree(tree);//видаляємо дерево
  return 0;
}