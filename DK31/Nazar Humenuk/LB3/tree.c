#include "tree.h"
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

Node *getSuccessor(Tree *tree, Node *toDelete);
void destroyNode(Node *Node);
void printNode(Node *node);

Tree *createTree(){//функція створення дерева
   Tree *tree = (Tree *)malloc(sizeof(Tree));//виділяємо память для дерева
  
   if(tree != NULL){//якщо вдалось виділити память
      tree->root = NULL;// перша коренева нода дорівнює NULL
      tree->size = 0;//РОЗМІР 0
   }

  return tree;//повертаємо дерево
}


Tree *fillTree(){//функція створення та заповнення дерева користувачем
  Tree *result = createTree();
  int kl = 0;// змінна кількості елементів
  printf("Введіть кількість значень, які бажаєте додати в дерево: ");
  while(scanf("%d", &kl) != 1 || kl < 1) {// отрмуємо кількість елементів від користувача та перевіряємо чи значення є числом та більше 0
      printf("Введено не число або не додатнє значення. Ведіть число : ");
    while (getchar() != '\n');// Очистення буфера введення
  }
  if (result != NULL) {//якщо вдалось виділити память
      float znach = 0;// змінна для значень дерева
      for (int i = 0; i < kl; i++) {// цикл для заповнення дерева
          printf("Введіть %d число: ", i + 1);
          if (scanf("%f", &znach) != 1) {// отримуємо значення елемену від користувача та перевіряємо чи воно є числом
              printf("Введено не число. ");
              while (getchar() != '\n'); // Очистення буфера введення
              i--; // Повторити спробу для цього ж числа
          } else {// якщо воно є числом
              insert(result, znach); // Додати новий елемент
          }
      }
  }
  return result;// повертаємо дерево
}



void insert(Tree *tree, float value){//функція додавання елементу до дерева
  if (NULL == tree)//якщо існує дерево
  {
    return;
  }

  Node *node = (Node *)malloc(sizeof(Node));//виділяємо память для нови
  
  if (NULL == node){//якщо вдалось виділити память
    return;
    
  }
  
  node->value = value;//записуємо значення в ноду
  node->leftChild = NULL;
  node->rightChild = NULL;
  
  if(NULL == tree->root){//якщо дерево порожнє
    tree->root = node;//назначаємо як кореневу ноду введену ноду
    
  }else {//якщо ні
    Node *theCurrent = tree->root;//створюємо тимчасові ноди
    Node *theParent = NULL;

    while (1){//запускаємо вічний цикл , поки не знайдемо місце для нової ноди
      theParent = theCurrent;//батькова нода позначається на ту саму ноду на яку тимчасова нода

      if (value < theCurrent->value){//якщо значення нової ноди менше ніж значення тимчасової ноди
        theCurrent = theCurrent->leftChild;//переходимо до лівої наступної ноди
        
        if (NULL == theCurrent){//якщо ліва наступна нода пуста
          theParent->leftChild = node;// вводимо нову ноду як наступну ліву ноду для батькової ноди
          break;//виходимо з циклу
          
        }
      }
      else{
        theCurrent = theCurrent->rightChild;//якщо значення нової ноди більше ніж значення тимчасової ноди
        
        if (NULL == theCurrent){//якщо права наступна нода пуста
          theParent->rightChild = node;// вводимо нову ноду як наступну праву ноду для батькової ноди
          break;//виходимо з циклу
          
        }
      }
    }
  }
  tree->size ++;//збільшуємо розмір дерева
  
}



void destroyElementByValue(Tree *tree, float value){//функція видалення елемента з дерева за значенням
  if (NULL == tree || NULL == tree->root){//якщо не існує дерева або дерево порожнє
   
    return;
    
  }
  
  Node *current = tree->root;//створюємо тимчасові ноди
  Node *parent = NULL;
  
  while (value != current->value) {//знаходимо ноду з вказазаним значенням, поки значення тимчасової ноди не співпаде з введеною
    parent = current;//батькова нода позначається на ту саму ноду на яку тимчасова нода
    if (value < current->value) {//якщо значення нової ноди менше ніж значення тимчасової ноди 
      current = current->leftChild;//переходимо до лівої наступної ноди
    } else {//якщо ні
      current = current->rightChild;//переходимо до правої наступної ноди
    }

    if (NULL == current) {//якщо тимчасова нода пуста , топто шуканої ноди за значенням у дереві не існує
      return ;
    }
  }

 if(NULL == current->leftChild && NULL == current->rightChild){//якщо нода не має дочірніх нод
   if (tree->root == current) {//якщо нода є коренем
     tree->root = NULL;// вказуємо що корінь дерева пусний
   } else if (parent->leftChild == current) {//якщо нода є лівою нодою батьківнської ноди 
     parent->leftChild = NULL;//вводимо що ліва наступна нода для батьківської пуста
   } else {//якщо нода є правою нодою батьківнської ноди 
     parent->rightChild = NULL;//вводимо що права наступна нода для батьківської пуста
   }

 }else if(NULL == current->leftChild){//якщо нода не має лівої наступної ноди
   if( tree->root == current){//якщо нода є коренем
     tree->root = current->rightChild;//вказуємо що корінь дерева тепер наступна прева нода для корення
   } else if (parent->leftChild == current) {//якщо нода є лівою нодою батьківнської ноди 
      parent->leftChild = current->rightChild;//вводимо що ліва наступна нода для батьківської рівна наступній правій ноді для тої ноди яку видаляють
    } else {//якщо нода є правою нодою батьківнської ноди 
      parent->rightChild = current->rightChild;//вводимо що права наступна нода для батьківської рівна наступній правій ноді для тої ноди яку видаляють
    }
 }else if(NULL == current->rightChild){//якщо нода не має правої наступної ноди
     if( tree->root == current){//якщо нода є коренем
       tree->root = current->leftChild;//вказуємо що корінь дерева тепер наступна ліва нода для корення
     } else if (parent->leftChild == current) {//якщо нода є лівою нодою батьківнської ноди 
        parent->leftChild = current->leftChild;//вводимо що ліва наступна нода для батьківської рівна наступній лівій ноді для тої ноди яку видаляють
      } else {//якщо нода є правою нодою батьківнської ноди 
        parent->rightChild = current->leftChild;//вводимо що права наступна нода для батьківської рівна наступній лівій ноді для тої ноди яку видаляють
      }
 } else {
   Node *successor = getSuccessor(tree, current);// знаходимо наступника для видаляємої ноди
   if (tree->root == current) {//якщо нода є коренем
     tree->root = successor;//вказуємо що коренем дерева є настпуник
   } else if (parent->leftChild == current) {//якщо нода є лівою нодою батьківнської ноди 
     parent->leftChild = successor;//вводимо що ліва наступна нода для батьківської рівна наступнику
   } else {//якщо нода є правою нодою батьківнської ноди 
     parent->rightChild = successor;//вводимо що права наступна нода для батьківської рівна наступнику
   }
 }
  current->leftChild = NULL;//очищаємо звязки для видаляємої ноди
  current->rightChild = NULL;
  destroyNode(current);//видаляємо ноду
 tree->size --;//зменшуємо розмір дерева
  
}


Node *findElementByValue(Tree *tree, float value){//функція знаходження елементу за значенням та повернення її
  Node *current = NULL;//створюємо тимчасову ноду
  if (NULL != tree && NULL != tree->root){//якщо існує терево та воно не пусте
    current = tree->root;// вводимо для тимчасової ноди кореневу ноду
    while (value != current->value){//знаходимо ноду з вказаним значенням , поки значення тимчасової ноди не співпаде з введеним значенням
        current = (value < current->value) ? current->leftChild: current->rightChild;//перехід тимчасовою ноди в залежності від введеного значення , якщо значення менше неж значення тимчасової ноди , то переходимо до наступної лівої ноди , а якщо більше то до правої

        if (NULL == current) {//якщо тимчасова нода пуста , топто шуканої ноди нема в дереві
          break;//виходимо з циклу
        }
      }
    }

    return current;//повертаємо тимчасову ноду
  
}


void destroyTree(Tree *tree){//функція видалення дерева
  if (NULL != tree) {//якщо дерево існує
      destroyNode(tree->root);//переходимо до фунції видалення ноди 
      free(tree);//звільняємо память від дерева
    }
  }


void printTree(Tree *tree) {//функція виводу дерева за допомогою симетричного обходу
  if (NULL == tree ){//якщо не існує дерева 
    return;
  }
  Node* item = tree->root;//створюємо тимчасову ноду як корень дерева
  printNode(item);//виводимо ноду та всі наступні привязані ноди , за допомогою функції
}

void printNode(Node *node) {//функція виводу ноди та всі наступні привязані ноди
  if (node == NULL)
    return;//якщо ноди не інує 
  

  printNode(node->leftChild);//виводимо всі елеменети для наступної лівої ноди за допомогою цієї самої функції 
  printf("Елемент: %.2f\n", node->value);//виводимо значення ноди 
  printNode(node->rightChild);//виводимо всі елеменети для наступної правої ноди за допомогою цієї самої функції 

}



void destroyNode(Node *Node)//функція видалення дерева
{
  if (NULL != Node)//якщо нода існує
  {
    destroyNode(Node->leftChild);//видаляємо всі елеменети для наступної лівої ноди за допомогою цієї самої функції 
    destroyNode(Node->rightChild);//видаляємо всі елеменети для наступної правої ноди за допомогою цієї самої функції 

    free(Node);//звільняємо память від видаленої ноди 
  }
}


Node *getSuccessor(Tree *tree, Node *toDelete) {//функція отримання наступника для видаленої ноди
  Node *successParent = toDelete;//створюємо тимчасові ноди  з вказівниками на ноду яку видаляємо
  Node *successor = toDelete;
  Node *current = toDelete->rightChild;//створюємо тимчасові ноди  з вказівниками на преву наступну ноду для ноди яку видаляємо

  while(NULL != current) {//знаходимо наступника для видаленої ноди , поки вказівник на нступний елемент не буде пустим
    successParent = successor;// переходимо батьківською нодою до наступника
    successor = current;// переходимо наступником до тимчасової ноди
    current = current->leftChild;// переходимо на наступну ліву ноду
  }
  if (successor != toDelete->rightChild) { //якщо наступник не є правою нодою для ноди , яку видаляємо 
    successParent->leftChild = successor->rightChild; //вводимо що наступна ліва нода для батьківської ноди є наступна права нода для наступника 
    successor->rightChild = toDelete->rightChild; // вводимо що наступна права нода для наступника це є наступна права нода  для ноди , яку видаляємо 
  }

  successor->leftChild = toDelete->leftChild;// вводимо що наступна ліва нода для наступника це є наступна ліва нода для ноди , яку видаляємо 

  return successor;//повертамо наступника для видаленої ноди
}
