#ifndef LIST_H
#define LIST_H

struct ListNodeTag {
  char *word;
  unsigned int length;

  struct ListNodeTag *nextNode;
};
typedef struct ListNodeTag ListNode;

struct ListTag {
  ListNode *head;
  ListNode *tail;

  unsigned int listSize;
};
typedef struct ListTag List;

List *createList();
void destroyList(List *list);

void readWordsFromUser(List *list);
void sortAndPrintLongestWords(List *list);

void printList(List *list);

#endif
