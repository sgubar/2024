#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  List *list = createList();
  add_to_end(list, 9);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 4);
  add_to_end(list, 5);
  
  printf("Прямий порядок:\n");
  print_forward(list->head);

  // Виведення елементів списку в зворотному порядку
  printf("Зворотний порядок:\n");
  print_backward(list->head);

  // Повторне виведення елементів списку в прямому порядку
  printf("\nПрямий порядок:\n");
  print_forward(list->head);

  // Повторне виведення елементів списку в зворотному порядку
  printf("Зворотний порядок:\n");
  print_backward(list->head);
  destroyList(list);
  return 0;
}
