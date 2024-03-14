#include <stdio.h>
#include "linkedlist.h"
int main() {
    struct Node* myList = createList(); // Створення пустого списку

    // Додавання елементів до списку
    append(&myList, 1);
    append(&myList, 2);
    append(&myList, 3);
    append(&myList, 4);
    append(&myList, 5);

    printf("Список: ");
    printList(myList); // Вивід списку на екран

    // Вилучення елементу зі списку
    deleteNode(&myList, 3);
    printf("Після вилучення: ");
    printList(myList);

    // Вставка елементу по індексу
    insertAtIndex(&myList, 2, 6);
    printf("Після вставки: ");
    printList(myList);

    // Видалення списку
    deleteList(&myList);

    return 0;
}

