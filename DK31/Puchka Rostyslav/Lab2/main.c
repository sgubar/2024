#include "list.h"
#include <stdio.h>

int main(void) {
  List *l = createList();

  // read list from user, and print it
  readWordsFromUser(l);
  printf("List is read from the user: ");
  printList(l);
  printf("\n");

  // sort list and print longest
  sortAndPrintLongestWords(l);

  destroyList(l);

  return 0;
}
