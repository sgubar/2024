#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct tagNode{//створенння структури ноди
  float value;// значення ноду у типі float
  struct tagNode *leftChild;//створення лівої наступної ноди
  struct tagNode *rightChild;//створення правої наступної ноди
}Node;

typedef struct tagTree {//створення структури для дерева
  Node *root;// перша коренева нода
  int size ;//розмір дерева
}Tree;

Tree *createTree();//функція створення дерева

Tree *fillTree();//функція заповнення дерева користувачем

void insert(Tree *tree, float value);//функція додавання елементу до дерева

void destroyElementByValue(Tree *tree, float value);//функція видалення елемента з дерева за значенням

Node *findElementByValue(Tree *tree, float value);//функція знаходження елементу за значенням та повернення її

void destroyTree(Tree *tree);//функція видалення дерева

void printTree(Tree *tree) ;//функція виводу дерева

void printNode(Node *node) ;//функція виводу ноди та всі наступні привязані ноди

#endif