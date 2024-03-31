#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// ������� ��� ��������� ������ ������
List *createList() {
    List *list = (List *)malloc(sizeof(List)); // �������� ���'�� ��� ������ ������
    if (list != NULL) { // �������� �� ������ �������� ���'��
        list->head = NULL; // ����������� ������ ������ �� NULL
        list->tail = NULL; // ����������� ������ ������ �� NULL
        list->size = 0;    // ����������� ������ ������ �� 0
    }
    return list; // ���������� ��������� �� ����� ������
}

// ������� ��� ��������� ������ ����� �� ���� ������
void appendToList(List *list, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // �������� ���'�� ��� ������ �����
    if (newNode != NULL) { // ���� �������� ���'�� ������
        newNode->data = value;    // ������������ �������� ��� �����
        newNode->next = NULL;     // ��������� ����� ����� �� NULL
        newNode->prev = list->tail; // ��������� ����� ����� �� �������� ���� ������

        if (list->tail) {
            list->tail->next = newNode; // ���� ���� ����, ��������� ���� ������ ��� ����� ������
        } else {
            list->head = newNode; // ���� ������ �������, ����� ����� ��� �������
        }
        list->tail = newNode; // ��������� ������ ������ �� ����� �����
        list->size++; // ��������� ������ ������
    }
}

// ������� ��� ������� ����� �� �������
void insertToList(List *list, int index, int value) {
    if (index < 0 || index > list->size) return; // �������� ���������� �������

    if (index == 0) { // ������� �� ������� ������
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode != NULL) {
            newNode->data = value;
            newNode->next = list->head;
            newNode->prev = NULL;
            if (list->head != NULL) {
                list->head->prev = newNode;
            }
            list->head = newNode;
            if (list->size == 0) { // ���� ������ ��� �������
                list->tail = newNode;
            }
            list->size++;
        }
    } else if (index == list->size) { // ������� �� ����� ������
        appendToList(list, value);
    } else { // ������� � �������� ������
        Node *current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode != NULL) {
            newNode->data = value;
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
            list->size++;
        }
    }
}

// ������� ��� ��������� ����� � ������ �� �������
void removeFromList(List *list, int index) {
    if (index < 0 || index >= list->size || list->head == NULL) return; // �������� ���������� ������� �� �������� �������� � ������

    Node *current = list->head;
    int i = 0;

    // ���������� �� ��������� �������
    while (i < index && current != NULL) {
        current = current->next;
        i++;
    }

    if (current == NULL) return; // ���� �������� ������ �������� �� ��� ��������

    // ��������� �����
    if (current->prev != NULL) { // ���� ����� �� ������
        current->prev->next = current->next;
    } else { // ���� ����� ������
        list->head = current->next;
    }

    if (current->next != NULL) { // ���� ����� �� �������
        current->next->prev = current->prev;
    } else { // ���� ����� �������
        list->tail = current->prev;
    }

    free(current); // ��������� ���'��, ������� �� �����
    list->size--; // ��������� ������ ������
}

// ������� ��� ��������� ������ ������
int listSize(List *list) {
    return list->size; // ��������� ����� ������
}

// ������� ��� ��������� ����� ������
void printList(List *list) {
    Node *current = list->head; // �������� � ������ ������
    printf("List: ");
    while (current != NULL) { // ��������� ����� ����� ������
        printf("%d ", current->data); // �������� ��� ��������� �����
        current = current->next; // ������� �� ���������� �����
    }
    printf("NULL\n"); // � ���� �������� NULL �� ������ ���� ������
}

// ������� ��� �������� ������ �� ��������� �������
void destroyList(List *list) {
    Node *current = list->head; // �������� � ������ ������
    while (current != NULL) { // ��������� ����� ����� ������
        Node *temp = current; // �������� �������� �� �������� �����
        current = current->next; // ������� �� ���������� �����
        free(temp); // ��������� ���'��, ������� ��� ��������� �����
    }
    free(list); // ��������� ���'��, ������� ��� ��������� ������
}
