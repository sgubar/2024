#include "tree.h"
#include <stdlib.h>

//static void - статична функція, що не повертає значення
static void destroyNode(IntNode *aNode); 
static IntNode *createIntNodeWithValue(int aValue);
static IntNode *getSuccessor(IntTree *tree, IntNode *toDelete);
static void print_int_node(IntNode *node);

IntTree *createIntTree() //створення дерева
{
  IntTree *theTree = (IntTree *)malloc(sizeof(IntTree)); //виділяємо пам'ять для дерева

  if (NULL != theTree)
  {
    theTree->root = NULL;
    theTree->count = 0;
  }

  return theTree;
} //обнулили все

void destroyIntTree(IntTree *aTree) //видаляємо дерево
{
  if (NULL != aTree)
  {
    destroyNode(aTree->root); //викликаємо destroyNode, кооли всі ноди видаляться
    free(aTree); //прибираємо дерево
  }
}

void insertIntValueToTree(IntTree *aTree, int aValue) //вставка елементу до дерева
{
  if (NULL == aTree) //перевірка на валідність дерева
  {
    return;
  }

  IntNode *theNode = createIntNodeWithValue(aValue); //створюємо нову ноду з значенням 
  if (NULL == theNode) //якщо ноди не створили
  {
    return; //повертаємось
  }

  if (NULL == aTree->root) //якщо на даний момент дерево пусте, то вставлений елелмент буде рутовим
  {
    aTree->root = theNode;
    aTree->count ++;
  }
  else //шукаємо місце для вставки елементу
  {
    IntNode *theCurrent = aTree->root;//починаємо шукати з кореня
    IntNode *theParent = NULL; 

    while (1) //нескінченний цикл, вихід з якого йде за допомогою break
    {
      theParent = theCurrent; 

      if (aValue < theCurrent->value) //в залежності від значення рута, обираємо шлях вліво чи вправо
      {
        theCurrent = theCurrent->leftChild; //якщо value<root, то шукаємо в лівій частині
        if (NULL == theCurrent)  
        {
          theParent->leftChild = theNode;
          break;
        }
      }
      else
      {
        theCurrent = theCurrent->rightChild;//якщо value>root, то шукаємо в правій частині
        if (NULL == theCurrent)
        {
          theParent->rightChild = theNode;
          break;
        }
      }
    }

    aTree->count ++;
  }
}

IntNode *findNodeWithValue(IntTree *aTree, int aValue)
{
  IntNode *theCurrentNode = NULL; //Якщо функція пошуку нічого не знайшла то вона повертає нуль
   //а якщо знайшла, то повертатиме посилання на ноду
  if (NULL != aTree && NULL != aTree->root)
  {
    theCurrentNode = aTree->root; //беремо рутовий елемент
    while (aValue != theCurrentNode->value)   //шукаємо ноду
    {
      theCurrentNode = (aValue < theCurrentNode->value) //якщо значення менше поточного елемента
            ? theCurrentNode->leftChild //шукаємо лівий елемент
            : theCurrentNode->rightChild; //якщо більше поточного елемента, то правий

      if (NULL == theCurrentNode) //якщо нода не знайшлася
      {
        break; //зупиняємо цикл
      }
    }
  }

  return theCurrentNode;
}

void deleteNodeWithValue(IntTree *aTree, int aValue) {

  if (NULL == aTree || NULL == aTree->root) {
    return ;
  }

  IntNode *current = aTree->root;
  IntNode *parent = aTree->root;

  while (aValue != current->value) {   //в даному циклі шукаємо ноду для видалення
    parent = current;
    if (aValue < current->value) {
      current = current->leftChild;
    } else {
      current = current->rightChild;
    }

    if (NULL == current) {
      return ;
    }
  }

  //1) the found node is leaf node? 
  //визначаємо чи є ця нода кінцевою
  if (NULL == current->leftChild && NULL == current->rightChild) { 
    if (aTree->root == current) {
      aTree->root = NULL;
    } else if (parent->leftChild == current) {
      parent->leftChild = NULL;
    } else {
      parent->rightChild = NULL;
    }
//робимо нулі для батьківського елемента

    //відбуваєтья від'єднання зв'язків та видалення ноди
    
    aTree->count --; //зменшення кількості елементів

    //видалення відносно правого елементу
  } else if (NULL == current->rightChild) {
    if (aTree->root == current) {
      aTree->root = current->leftChild;
    } else if (parent->leftChild == current) {
      parent->leftChild = current->leftChild;
    } else {
      parent->rightChild = current->rightChild;
    }
    //видалення відносно лівого елементу
  } else if (NULL == current->leftChild) {
    if (aTree->root == current) {
      aTree->root = current->rightChild;
    } else if (parent->rightChild == current) {
      parent->rightChild = current->rightChild;
    } else {
      parent->leftChild = current->leftChild;
    }
    //видалення при лівому й правому елементі
  } else {
    IntNode *successor = getSuccessor(aTree, current); //шукаємо ноду, яка стане новим батьківським елементом 
    if (aTree->root == successor) {
      aTree->root = NULL;
    } else if (parent->leftChild == current) {
      parent->leftChild = successor;
    } else {
      parent->rightChild = successor;
    }
    current->leftChild = NULL;
    current->rightChild = NULL;
  } //процеси витягуваня ноди з дерева 

  destroyNode(current); //видалення ноди
}

void printTree(IntTree *aTree) {
  IntNode* item = aTree->root;
  print_int_node(item);
}

void print_int_node(IntNode *node) {
  if (node == NULL)
    return;
  print_int_node(node->leftChild); //по максимуму вліво, друкуємо елемент
  printf("Элемент: %d\n", node->value);
  print_int_node(node->rightChild); //по максимуму вправо
  //обхід симетричний при друці
}
 void printNode(IntNode *aNode){
   if (aNode == NULL)
     return;
   printf("value:(%d)\n", aNode->value);
   
 }

void destroyNode(IntNode *aNode)
{
  if (NULL != aNode)
  {
    destroyNode(aNode->leftChild); //спочатку йдемо по максиуму вліво
    destroyNode(aNode->rightChild); //після видалення лівого піддерева, йдемо по максимуму вправо (використання рекурсії)

    free(aNode); //видаляємо ліву ноду //видаляємо праву ноду //потім видаляємо кореневий елемент і т.д.
    /// Тобто обхід дерева є зворотнім
  }
}

IntNode *createIntNodeWithValue(int aValue) //створення ноди за значеннням
{
  IntNode *theNode = (IntNode *)malloc(sizeof(IntNode)); //виділення пам'яті для ноди

  if (NULL != theNode)
  {
    theNode->leftChild = NULL;
    theNode->rightChild = NULL;
    theNode->value = aValue;
  }

  return theNode;
}

IntNode *getSuccessor(IntTree *tree, IntNode *toDelete) { //маємо ноду toDelete. Тобто потрібно обрати ноду, що буде знаходитись між значеннями лівого та правого нащадка
  IntNode *successParent = toDelete;
  IntNode *successor = toDelete;
  IntNode *current = toDelete->rightChild; //починаємо з правого нащадка. Тобто перебираємо елементи, які підходитимуть для successor

  while(NULL != current) {
    successParent = successor;
    successor = current;
    current = current->leftChild;
  }

  if (successor != toDelete->rightChild) { 
    successParent->leftChild = successor->rightChild; 
    successor->rightChild = toDelete->rightChild; 
  } //якщо successor не є правим нащадком toDelete, то його правий нащадок буде правим нащадком successParent

  successor->leftChild = toDelete->leftChild; //прив'язуємо successor з лівим нащадком toDelete

  return successor;
}
