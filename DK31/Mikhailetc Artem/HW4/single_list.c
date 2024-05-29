#include "single_list.h"
#include <stdio.h>
#include <stdlib.h>

SingleListIntElement *createSingleListIntElement(int value) {
    SingleListIntElement *result = (SingleListIntElement *)malloc(sizeof(SingleListIntElement));
    if (NULL != result) {
        result->value = value;
        result->next = NULL;
    }
    return result;
}

void deleteSingleListIntElement(SingleListIntElement *element) {
    if (NULL != element) {
        free(element);
    }
}

void printSingleListIntElement(SingleListIntElement *element) {
    if (NULL != element) {
        printf("%d", element->value);
    }
}

IntSingleList *createIntSingleList(void) {
    IntSingleList *result = (IntSingleList *)malloc(sizeof(IntSingleList));
    if (NULL != result) {
        result->head = NULL;
    }
    return result;
}

void deleteIntSingleList(IntSingleList *list) {
    if (NULL == list) {
        return;
    }
    SingleListIntElement *element = list->head;
    while (NULL != element) {
        SingleListIntElement *nn = element->next;
        free(element);
        element = nn;
    }
    free(list);
}

void printIntSingleList(IntSingleList *list) {
    if (NULL == list) {
        printf("Invalid pointer to the list\n");
        return;
    }
    printf("[");
    for (SingleListIntElement *element = list->head; element != NULL; element = element->next) {
        printSingleListIntElement(element);
        if (element->next != NULL) {
            printf(",");
        }
    }
    printf("]\n");
}

long countOfIntSingleList(IntSingleList *list) {
    if (NULL == list) {
        return 0;
    }
    long count = 0;
    for (SingleListIntElement *element = list->head; element != NULL; element = element->next, count++);
    return count;
}

int addIntValueToIntSingleList(IntSingleList *list, int value) {
    if (NULL == list) {
        return 0;
    }
    SingleListIntElement *element = createSingleListIntElement(value);
    if (NULL == element) {
        return 0;
    }
    if (NULL == list->head) {
        list->head = element;
        return 1;
    }

    SingleListIntElement *tail = list->head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = element;
    return 1;
}

void removeLastElementFromIntSingleList(IntSingleList *list) {
    if (NULL == list || NULL == list->head) {
        return;
    }
    SingleListIntElement *element = list->head;
    if (NULL == element->next) {
        list->head = NULL;
        deleteSingleListIntElement(element);
        return;
    }
    while (element->next->next != NULL) {
        element = element->next;
    }
    deleteSingleListIntElement(element->next);
    element->next = NULL;
}

void removeFirstElementFromIntSingleList(IntSingleList *list) {
    if (NULL == list || NULL == list->head) {
        return;
    }
    SingleListIntElement *element = list->head->next;
    deleteSingleListIntElement(list->head);
    list->head = element;
}

int insertIntElementToIntSingleListAtIndex(IntSingleList *list, int index, int value) {
    if (NULL == list) {
        return 0;
    }
    long count = countOfIntSingleList(list);
    if (index > count) {
        return 0;
    }
    SingleListIntElement *element = createSingleListIntElement(value);
    if (NULL == element) {
        return 0;
    }
    if (0 == index) {
        element->next = list->head;
        list->head = element;
    } else {
        int current = 0;
        SingleListIntElement *ex_element = list->head;
        for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++);
        element->next = ex_element->next;
        ex_element->next = element;
    }
    return 1;
}

int removeIntElementFromIntSingleListAtIndex(IntSingleList *list, int index) {
    if (NULL == list) {
        return 0;
    }
    long count = countOfIntSingleList(list);
    if (index >= count) {
        return 0;
    }
    if (0 == index) {
        removeFirstElementFromIntSingleList(list);
        return 1;
    } else if (index == count - 1) {
        removeLastElementFromIntSingleList(list);
        return 1;
    } else {
        int current = 0;
        SingleListIntElement *ex_element = list->head;
        for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++);
        SingleListIntElement *to_delete = ex_element->next;
        ex_element->next = to_delete->next;
        deleteSingleListIntElement(to_delete);
    }
    return 1;
}
