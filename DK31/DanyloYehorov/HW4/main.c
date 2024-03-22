#include "list.h"
#include <stdio.h>

void listInfo(List *l, char *prefix);
void generalTests(void);
void oorTests(void);

int main(void) {
  generalTests();
  oorTests();

  return 0;
}

void oorTests(void) {
  List *l = createList();

  printf("//------- OUT-OF-RANGE TESTS -------//\n\n");

  appendNumberToList(l, 2.3);
  appendNumberToList(l, 4.2);
  appendNumberToList(l, 5.1);

  //---------------------------
  listInfo(l, "Deleting out of range (10):\nBefore");

  deleteNumberFromList(l, 10);

  listInfo(l, "\nAfter ");

  //---------------------------
  listInfo(l, "Deleting out of range (3):\nBefore");

  deleteNumberFromList(l, 3);

  listInfo(l, "\nAfter ");

  //---------------------------
  listInfo(l, "\n\nInserting out of range (10):\nBefore");

  insertNumberToList(l, 10, 0.1);

  listInfo(l, "\nAfter ");

  //---------------------------
  listInfo(l, "\n\nInserting out of range (3):\nBefore");

  insertNumberToList(l, 3, 0.1);

  listInfo(l, "\nAfter ");

  //---------------------------
  printf("\n\n");

  destroyList(l);
}

void generalTests(void) {
  List *l = NULL;

  printf("//------- GENERAL TESTS -------//\n\n");

  //---------------------------
  listInfo(l, "Creation:\nBefore");

  l = createList();

  listInfo(l, "\nAfter ");

  //---------------------------
  listInfo(l, "\n\nAppending:\nBefore");

  appendNumberToList(l, 2.3);
  appendNumberToList(l, 4.2);
  appendNumberToList(l, 5.1);
  appendNumberToList(l, 6.9);

  listInfo(l, "\nAfter ");

  //---------------------------
  listInfo(l, "\n\nDeleting (index=0, first):\nBefore");

  deleteNumberFromList(l, 0);

  listInfo(l, "\nAfter ");

  //---------------------------
  listInfo(l, "\n\nDeleting (index=1):\nBefore");

  deleteNumberFromList(l, 1);

  listInfo(l, "\nAfter ");

  //---------------------------
  listInfo(l, "\n\nDeleting (index=1, last) and appending:\nBefore");

  deleteNumberFromList(l, 1);
  appendNumberToList(l, 2.3);

  listInfo(l, "\nAfter ");

  //---------------------------
  listInfo(l, "\n\nInserting (index=0, first):\nBefore");

  insertNumberToList(l, 0, 0.6);

  listInfo(l, "\nAfter ");

  //---------------------------
  listInfo(l, "\n\nInserting (index=1):\nBefore");

  insertNumberToList(l, 1, 9.9);

  listInfo(l, "\nAfter ");

  //---------------------------
  printf("\n\n");

  destroyList(l);
}

void listInfo(List *l, char *prefix) {
  printf("\n%s", prefix);
  printf(" | size: %u | ", listSize(l));
  printList(l);
}
