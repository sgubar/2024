#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct tagNode //Описуємо вузол дерева, що містить значення та посилання на ліве та праве піддерева
{
  int value; 
  struct tagNode *leftChild;
  struct tagNode *rightChild;
} IntNode;

typedef struct tagTree //Дерево
{
IntNode *root; //посилання на корінь дерева
  int count; //поточна кількість елементів дерева
} IntTree;


IntTree *createIntTree(); //створення дерева
void destroyIntTree(IntTree *aTree); //видалення дерева

void insertIntValueToTree(IntTree *aTree, int aValue); //вставляє елементи в дерево
IntNode *findNodeWithValue(IntTree *aTree, int aValue); //пошук елемента дерева
void deleteNodeWithValue(IntTree *aTree, int aValue); //видалення елемента дерева


void printTree(IntTree *aTree); //виведення дерева
void printNode(IntNode *aNode);
int countNodesWithTree(IntTree *aTree); //повертає кількість елементів дерева

#endif
