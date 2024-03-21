#include <stdio.h>
#include <stdlib.h>
#include "twolist.h"
int main(void) {
  printf( "Hello World\n" );
  printf("*** TEST LINKED LIST *** \n");
  Double2List *l = createDouble2List();

  printDouble2List(l);

  addDoubleValueToDouble2List(l, 5);
  printDouble2List(l);

  addDoubleValueToDouble2List(l, 10);
  printDouble2List(l);

  insertDoubleElementToDouble2ListAtIndex(l, 1, 2);
  printDouble2List(l);

  addDoubleValueToDouble2List(l, 8);
  printDouble2List(l);

  insertDoubleElementToDouble2ListAtIndex(l, 2, 3);
  printDouble2List(l);

  removeFirstElementFromDouble2List(l);
  printDouble2List(l);

  removeLastElementFromDouble2List(l);
  printDouble2List(l);

  printf("*** END OF TEST LINKED LIST *** \n");
  printf("Goodbye, World!\n");

  deleteDouble2List(l);
  return 0;
 
}
