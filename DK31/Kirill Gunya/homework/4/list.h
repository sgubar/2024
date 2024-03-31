#ifndef LIST_H
#define LIST_H

// ��������� ��� ������������� ���� ����������� ������
typedef struct Node {
    int data;            // ������ ����
    struct Node *next;   // ��������� �� ��������� ����
    struct Node *prev;   // ��������� �� ���������� ����
} Node;

// ��������� ��� ������������� ����������� ������
typedef struct {
    Node *head;          // ��������� �� ������ ������
    Node *tail;          // ��������� �� ����� ������
    int size;            // ������ ������
} List;

// ��������� �������
List *createList();                  // �������� ������
void appendToList(List *list, int value); // ���������� �������� � ����� ������
void insertToList(List *list, int index, int value); // ������� �������� �� �������
void removeFromList(List *list, int index); // �������� �������� �� �������
void printList(List *list);            // ����� ������ �� �����
int listSize(List *list);              // ��������� ������� ������
void destroyList(List *list);          // �������� ������

#endif
