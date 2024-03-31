#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Функція для створення нового списку
List *createList() {
    List *list = (List *)malloc(sizeof(List)); // Виділення пам'яті для нового списку
    if (list != NULL) { // Перевірка на успішне виділення пам'яті
        list->head = NULL; // Ініціалізація голови списку як NULL
        list->tail = NULL; // Ініціалізація хвоста списку як NULL
        list->size = 0;    // Ініціалізація розміру списку як 0
    }
    return list; // Повернення вказівника на новий список
}

// Функція для додавання нового вузла до кінця списку
void appendToList(List *list, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Виділення пам'яті для нового вузла
    if (newNode != NULL) { // Якщо виділення пам'яті успішне
        newNode->data = value;    // Встановлення значення для вузла
        newNode->next = NULL;     // Наступний вузол вказує на NULL
        newNode->prev = list->tail; // Попередній вузол вказує на поточний хвіст списку

        if (list->tail) {
            list->tail->next = newNode; // Якщо хвіст існує, наступний після хвоста стає новим вузлом
        } else {
            list->head = newNode; // Якщо список порожній, новий вузол стає головою
        }
        list->tail = newNode; // Оновлення хвоста списку на новий вузол
        list->size++; // Збільшення розміру списку
    }
}

// Функція для вставки вузла по індексу
void insertToList(List *list, int index, int value) {
    if (index < 0 || index > list->size) return; // Перевірка коректності індексу

    if (index == 0) { // Вставка на початок списку
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode != NULL) {
            newNode->data = value;
            newNode->next = list->head;
            newNode->prev = NULL;
            if (list->head != NULL) {
                list->head->prev = newNode;
            }
            list->head = newNode;
            if (list->size == 0) { // Якщо список був порожній
                list->tail = newNode;
            }
            list->size++;
        }
    } else if (index == list->size) { // Вставка на кінець списку
        appendToList(list, value);
    } else { // Вставка в середину списку
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

// Функція для видалення вузла зі списку по індексу
void removeFromList(List *list, int index) {
    if (index < 0 || index >= list->size || list->head == NULL) return; // Перевірка коректності індексу та наявності елементів у списку

    Node *current = list->head;
    int i = 0;

    // Переміщення до вказаного індексу
    while (i < index && current != NULL) {
        current = current->next;
        i++;
    }

    if (current == NULL) return; // Якщо вказаний індекс виходить за межі діапазону

    // Вилучення вузла
    if (current->prev != NULL) { // Якщо вузол не перший
        current->prev->next = current->next;
    } else { // Якщо вузол перший
        list->head = current->next;
    }

    if (current->next != NULL) { // Якщо вузол не останній
        current->next->prev = current->prev;
    } else { // Якщо вузол останній
        list->tail = current->prev;
    }

    free(current); // Звільнення пам'яті, виділеної під вузол
    list->size--; // Зменшення розміру списку
}

// Функція для отримання розміру списку
int listSize(List *list) {
    return list->size; // Повертаємо розмір списку
}

// Функція для виведення вмісту списку
void printList(List *list) {
    Node *current = list->head; // Починаємо з голови списку
    printf("List: ");
    while (current != NULL) { // Проходимо через увесь список
        printf("%d ", current->data); // Виводимо дані поточного вузла
        current = current->next; // Перехід до наступного вузла
    }
    printf("NULL\n"); // В кінці виводимо NULL як ознаку кінця списку
}

// Функція для знищення списку та звільнення ресурсів
void destroyList(List *list) {
    Node *current = list->head; // Починаємо з голови списку
    while (current != NULL) { // Проходимо через увесь список
        Node *temp = current; // Зберігаємо вказівник на поточний вузол
        current = current->next; // Перехід до наступного вузла
        free(temp); // Звільнення пам'яті, виділеної для поточного вузла
    }
    free(list); // Звільнення пам'яті, виділеної для структури списку
}
