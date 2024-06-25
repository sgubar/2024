#include "list.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Internal functions
void appendSWordToList(List *list, char *string);
void addWordToList(List *list);

List *createList() {
  List *result = malloc(sizeof(List));

  // if memory allocated succesfully, setup default values
  if (NULL != result) {
    result->head = NULL;
    result->tail = NULL;

    result->listSize = 0;
  }

  return result;
}

void destroyList(List *list) {
  // if list empty do nothing
  if (NULL == list) {
    return;
  }

  // set start values
  ListNode *toDelete = list->head;
  ListNode *next = toDelete->nextNode;

  // cycle through all elements and them
  while (toDelete != NULL) {
    next = toDelete->nextNode;
    free(toDelete->word);
    free(toDelete);
    toDelete = next;
  }

  // delete "main" structure
  free(list);
}

void removeElementInList(List *list, char *str) {
  if (NULL == list) {
    return;
  }

  ListNode *previous = NULL;
  ListNode *current = list->head;

  // if element is head
  if (strcmp(str, current->word) == 0) {
    list->head = current->nextNode;
  }

  while (NULL != current) {
    if (strcmp(str, current->word) == 0) {

      return;
    }
  }
}

void printNode(ListNode *node) {
  if (NULL == node) {
    printf("NULL");
    return;
  }

  printf("%s -> ", node->word);
  printNode(node->nextNode);
}

void printList(List *list) {
  if (NULL == list) {
    printf("(LIST POINTER IS NULL)");
    return;
  }
  printNode(list->head);
}

void appendWordToList(List *list, char *string) {
  int stringSize = sizeof(char) * (strlen(string) + 1);

  ListNode *newNode = (ListNode *)malloc(sizeof(newNode));

  if (list->listSize == 0) {
    // list is empty, set new head
    list->head = newNode;
  } else {
    // list isn't empty, set pointer of last node
    list->tail->nextNode = newNode;
  }

  // set new tail and increase counter
  list->tail = newNode;
  list->listSize++;

  // set values of new node
  newNode->nextNode = NULL;

  newNode->word = (char *)malloc(stringSize);
  memcpy(newNode->word, string, stringSize);

  newNode->length = strlen(string);
}

void bubbleSort(List *list) {
  // sort words only if list long enough (at least 2 elements)
  if (2 > list->listSize) {
    return;
  }
  int changed = 0;

  ListNode *previous = NULL;
  ListNode *first = list->head;
  ListNode *second = first->nextNode;

  while (first->nextNode != NULL) {
    if (first->length < second->length) {
      // swap nodes
      first->nextNode = second->nextNode;
      second->nextNode = first;

      if (previous == NULL) {
        // first node
        list->head = second;
      } else {
        // somewhere inside
        previous->nextNode = second;
      }
      previous = second;

      changed = 1;
    } else {
      // just proccess to next node
      first = second;
    }

    // set new second node
    second = first->nextNode;
  }

  // if changes was made, repeat sort
  if (changed == 1) {
    bubbleSort(list);
  }
}

void sortAndPrintLongestWords(List *list) {
  // return if list don't exist
  if (NULL == list) {
    printf("Invalid list pointer.");
    return;
  }

  // return if list is empty
  if (0 == list->listSize) {
    printf("List is empty!\n");
    return;
  }

  // sort words by length, from longest to shortest
  bubbleSort(list);

  // print sorted list
  printf("Sorted list: ");
  printList(list);

  // save max length
  unsigned int maxLength = list->head->length;

  // print nodes until    current length == max length
  printf("\nLongest words:\n");
  ListNode *current = list->head;
  while (current->length == maxLength && current != NULL) {
    printf("%s\n", current->word);
    current = current->nextNode;
  }
}

int isWord(char *str) {
  while (*str != '\0') {
    if (!isalpha(*str)) {
      return 0;
    }

    str++;
  }

  return 1;
}

// return 0 if word ends with \n
// return 1 if word ends with space
int readOneWord(char *str, int maxSize) {
  int cnt = 0;

  // read one word, but not more than 100 chars
  while (1) {
    str[cnt] = (char)getchar();

    if (str[cnt] == '\n') {
      str[cnt] = '\0';
      return 0;
    } else if (str[cnt] == ' ') {
      str[cnt] = '\0';
      return 1;
    }

    if (cnt < maxSize - 1) {
      cnt++;
    }
  }
}

void readWordsFromUser(List *list) {
  char input_buffer[100];
  int result;

  printf("Write words separated with spaces.\n");

  // cycle through all words and add them to list if it's actually words
  do {
    result = readOneWord(input_buffer, 100);
    if (isWord(input_buffer) == 1) {
      appendWordToList(list, input_buffer);
    }
  } while (result);
}
