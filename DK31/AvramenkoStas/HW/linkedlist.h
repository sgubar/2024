#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Структура вузла списку
typedef struct Node {
    int data;           // Дані, що зберігаються у вузлі
    struct Node* next;  // Покажчик на наступний вузол
} Node;

// Функції для роботи зі списком
Node* create_node(int data);                    // Функція створення нового вузла
void add_element(Node** head, int data);        // Функція додавання елемента до списку
void remove_element(Node** head, int data);     // Функція видалення елемента зі списку
void insert_element(Node** head, int index, int data);  // Функція вставки елемента за індексом
void delete_list(Node** head);                  // Функція видалення всього списку
int size(Node* head);                           // Функція отримання розміру списку
void display(Node* head);                       // Функція виведення списку на екран

#endif

