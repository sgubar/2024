#include "tree.h"
#include <stdio.h>

// Функція для введення нового значення в дерево
void insertUserValue(DoubleTree *tree) {
    double value;
    printf("Введіть нове значення: ");
    scanf("%lf", &value);
    insertDoubleValueToTree(tree, value);
}

// Функція для видалення значення з дерева
void deleteUserValue(DoubleTree *tree) {
    double value;
    printf("Введіть значення, яке потрібно видалити: ");
    scanf("%lf", &value);
    deleteNodeWithValue(tree, value);
}

// Функція для пошуку значення в дереві
void searchUserValue(DoubleTree *tree) {
    double value;
    printf("Введіть значення, яке потрібно знайти: ");
    scanf("%lf", &value);
    DoubleNode *node = findNodeWithValue(tree, value);
    if (node != NULL) {
        printf("Значення знайдено: ");
        printNode(node);
        printf("\n");
    } else {
        printf("Значення не знайдено.\n");
    }
}

int main() {
  DoubleTree *tree = createDoubleTree();
  insertDoubleValueToTree(tree, 43.0);
  insertDoubleValueToTree(tree, 65.0);
  insertDoubleValueToTree(tree, 30.0);
  insertDoubleValueToTree(tree, 14.0);
  insertDoubleValueToTree(tree, 9.0);
  insertDoubleValueToTree(tree, 23.0);
  insertDoubleValueToTree(tree, 35.0);
  insertDoubleValueToTree(tree, 98.0);
  insertDoubleValueToTree(tree, 99.0);
  insertDoubleValueToTree(tree, 57.0);
  insertDoubleValueToTree(tree, 87.0);

  char choice;
  do {
      printf("\nВиберіть опцію:\n");
      printf("1. Ввести нове значення\n");
      printf("2. Видалити значення\n");
      printf("3. Знайти значення\n");
      printf("4. Вивести дерево\n");
      printf("5. Вийти\n");

      scanf(" %c", &choice);

      switch (choice) {
          case '1':
              insertUserValue(tree);
              break;
          case '2':
              deleteUserValue(tree);
              break;
          case '3':
              searchUserValue(tree);
              break;
          case '4':
              printTree(tree);
              break;
          case '5':
              printf("До побачення!\n");
              break;
          default:
              printf("Неправильний вибір. Спробуйте ще раз.\n");
      }
  } while (choice != '5');

  destroyDoubleTree(tree);

  return 0;
}
