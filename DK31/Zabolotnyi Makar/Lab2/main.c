#include <stdio.h>
#include <stdlib.h>
#include "doptwolist.h"
int main(void) {
  printf( "Hello World\n" );
  printf("*** TEST LINKED LIST *** \n");
  Double2List *l = createDouble2List();

  printDouble2List(l);
  int value;
  char choice;
  // Запитуємо у користувача введення значень
  do {
      printf("Введіть ціле число: ");
      scanf("%d", &value);
      addDoubleValueToDouble2List(l, value);
      doubleElement(l, value);
      printf("Продовжити введення? (press a or l on keyboard): ");
      scanf(" %c", &choice);
  } while (choice == 'l' || choice == 'L' || choice == 'a' || choice == 'A');

  // Виводимо список
  printf("Двозв'язний список:\n");
  printDouble2List(l);
  
  printf("*** END OF TEST LINKED LIST *** \n");
  printf("Goodbye, World!\n");
  
  deleteDouble2List(l);
  return 0;

}
