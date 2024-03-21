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



void insertNumberToList(List *list, unsigned int index, double number) {
    ListNode *previous, *current = list->head;
    unsigned int i = 0;

    if (index >= listSize(list)) {
        return;
    }

    // create node
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    if (node == NULL) {
        return;
    }
    node->number = number;

    // if head element
    if (index == 0) {
        list->head = node;
        node->next = current;
        list->count++;

        return;
    }

    // cycle through list until index
	while (current != NULL && i != index) {
        previous = current;
		current = current->next;
		i++;
	}

	previous->next = node;
	node->next = current;

	list->count++;
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

    if (index >= listSize(list)) {
        return;
    }

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



unsigned int listSize(List *list) {
    if (list != NULL) {
        return list->count;
    }

    return -1; // return max possible number
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
