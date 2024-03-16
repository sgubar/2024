#include "single_list.h"
#include <stdio.h>
#include <stdlib.h>
int main(void) {

  FloatSingleList *list = createFloatSingleList();

  printFloatSingleList(list);

  addFloatValueToFloatSingleList(list, 5);
  printFloatSingleList(list);

  addFloatValueToFloatSingleList(list, 6);
  printFloatSingleList(list);

  removeFirstElementFromFloatSingleList(list);
  printFloatSingleList(list);

  removeLastElementFromFloatSingleList(list);
  printFloatSingleList(list);

  deleteFloatSingleList(list);
  return 0;
}
