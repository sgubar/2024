#include "list.h"

#include <stdlib.h>
#include <stdio.h>

List *createList(void) {
    List *result = (List *) malloc(sizeof(List));

    // if List pointer not null setup initial constants
    if (result != NULL) {
        result->count = 0;
        result->head = NULL;
        result->tail = NULL;
    }

    return result;
}



void destroyList(List *list) {
    if (list == NULL) {
		return ;
	}

	ListNode *node = list->head;

    // destroy every node
	while (NULL != node) {
		ListNode *next = node->next;
		free(node);
		node = next;
	}

	free(list);
}



List *getListFromUser(void) {
    List *result = createList();

    if (result != NULL) {
        double number;

        printf("Enter numbers separated by spaces and ending with a character that is not a number.\n");
        while (scanf("%lf", &number)) {
            appendNumberToList(result, number);
        }
    }

    return result;
}



void deleteDuplicates(List *list) {
    if (list == NULL) {
		return;
	}

    unsigned int i;

    for (i = 0; i < list->count; i++) {
        if (numberInList(list, numberAtIndex(list, i), i)) {
            deleteNumberFromList(list, i);
            i--;
        }
    }
}



void appendNumberToList(List *list, double number) {
	if (list == NULL) {
		return;
	}

	ListNode *node = (ListNode *) malloc(sizeof(ListNode));
	if (node == NULL) {
		return;
	}

	node->number = number;
	node->next = NULL;

	if (list->head == NULL) {
        // if list empty
		list->head = list->tail = node;
	} else {
        // if list not empty
		list->tail->next = node;
		list->tail = node;
	}

	list->count++;
}



void deleteNumberFromList(List *list, unsigned int index) {
    ListNode *previous, *current = list->head;
    unsigned int i = 0;

    // if head element
    if (index == 0) {
        list->head = current->next;
        list->count--;

        free(current);

        return;
    }

    // cycle through list until index
	while (current != NULL && i != index) {
        previous = current;
		current = current->next;
		i++;
	}

	previous->next = current->next;
	free(current);

	if ((index + 1) == list->count) {
        // if last element deleted -> set new tail
        list->tail = previous;
	}

	list->count--;
}



signed char numberInList(List *list, double number, unsigned int endIndex) {
    if (list == NULL) {
		return -1;
	}

	ListNode *node = list->head;
	unsigned int i = 0;

    // check every node until index
    while (node != NULL && i != endIndex) {
        if (node->number == number) {
            // if number found -> return 1 (true)
            return 1;
        }

		node = node->next;
		i++;
	}

	return 0;
}



double numberAtIndex(List *list, unsigned int index) {
    if (list == NULL || index > list->count) {
		return 0;
	}

	ListNode *node = list->head;
	unsigned int i = 0;

    // cycle through list
	while (node != NULL && i != index) {
		node = node->next;
		i++;
	}

	return node->number;
}



void printList(List *list) {
    if (list == NULL) {
		printf("ERROR");
		return;
	}

	if (list->head == NULL) {
		printf("(empty)");
		return;
	}

    ListNode *node = list->head->next;
    printf("%lf", list->head->number);

    while (node != NULL) {
        printf(" -> %lf", node->number);
		node = node->next;
	}
}
