#ifndef LIST_H
#define LIST_H

// Структура для представления узла двусвязного списка
typedef struct Node {
    int data;            // Данные узла
    struct Node *next;   // Указатель на следующий узел
    struct Node *prev;   // Указатель на предыдущий узел
} Node;

// Структура для представления двусвязного списка
typedef struct {
    Node *head;          // Указатель на начало списка
    Node *tail;          // Указатель на конец списка
    int size;            // Размер списка
} List;

// Прототипы функций
List *createList();                  // Создание списка
void appendToList(List *list, int value); // Добавление элемента в конец списка
void insertToList(List *list, int index, int value); // Вставка элемента по индексу
void removeFromList(List *list, int index); // Удаление элемента по индексу
void printList(List *list);            // Вывод списка на экран
int listSize(List *list);              // Получение размера списка
void destroyList(List *list);          // Удаление списка

#endif
