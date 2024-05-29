#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* create_list() {
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add_element(List *list, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void delete_element(List *list, int data) {
    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return; // Елемент не знайдено
    }

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    list->size--;
}

void insert_element(List *list, int data, int index) {
    if (index < 0 || index > list->size) {
        return;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;

    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    list->size++;
}

void destroy_list(List *list) {
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

int get_size(List *list) {
    return list->size;
}

void print_list(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
