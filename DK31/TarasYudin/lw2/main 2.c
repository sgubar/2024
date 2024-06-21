#include <stdio.h>
#include <stdlib.h>

// Визначення структури вузла двозв'язного списку
typedef struct listElement {
    int data;
    struct listElement* next;
    struct listElement* prev;
} listElement;

// Функція для створення нового вузла
listElement* createListElement(int data) {
    listElement* newListElement = (listElement*)malloc(sizeof(listElement));
    newListElement->data = data;
    newListElement->next = NULL;
    newListElement->prev = NULL;
    return newListElement;
}

// Функція для додавання вузла в кінець списку
void append(listElement** head, int data) {
    listElement* newListElement = createListElement(data);
    listElement* last = *head;

    if (*head == NULL) {
        *head = newListElement;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newListElement;
    newListElement->prev = last;
}

// Функція для виведення списку у прямому порядку
void printListForward(listElement* head) {
    listElement* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Функція для виведення списку у зворотному порядку
void printListBackward(listElement* head) {
    listElement* temp = head;

    if (head == NULL) return;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main() {

    listElement* head = NULL;
    int n, data;

    printf("Введіть кількість елементів списку: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Неправильний ввід! Введіть ціле число більше нуля: ");
        while (getchar() != '\n'); // Очищення буфера
    }

    for (int i = 0; i < n; i++) {
        printf("Введіть елемент %d: ", i + 1);
        while (scanf("%d", &data) != 1) {
            printf("Неправильний ввід! Введіть ціле число: ");
            while (getchar() != '\n'); // Очищення буфера
        }
        append(&head, data);
    }

    printf("Список у прямому порядку (перший раз): ");
    printListForward(head);
    printf("\n");

    printf("Список у прямому порядку (другий раз): ");
    printListForward(head);
    printf("\n");

    printf("Список у зворотному порядку (перший раз): ");
    printListBackward(head);
    printf("\n");

    printf("Список у зворотному порядку (другий раз): ");
    printListBackward(head);
    printf("\n");

    return 0;
}