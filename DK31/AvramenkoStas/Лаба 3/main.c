#include "binary_tree.h"
#include <stdio.h>

int main() {
    struct Node* root = NULL;
    int num;
    
    printf("Введіть числа для дерева (для завершення введіть -1):\n");
    while (1) {
        printf("Введіть число: ");
        scanf("%d", &num);
        if (num == -1)
            break;
        root = insert(root, num);
    }
    
    printf("Бінарне дерево (ін-ордер обхід): ");
    printTree(root);
    printf("\n");
    
    int key_to_find;
    printf("Введіть число для пошуку: ");
    scanf("%d", &key_to_find);
    struct Node* foundNode = search(root, key_to_find);
    if (foundNode != NULL)
        printf("Знайдений вузол з ключем %d\n", foundNode->data);
    else
        printf("Вузол з ключем %d не знайдений\n", key_to_find);
    
    int key_to_delete;
    printf("Введіть число для видалення: ");
    scanf("%d", &key_to_delete);
    root = deleteNode(root, key_to_delete);
    printf("Бінарне дерево після видалення елементу з ключем %d: ", key_to_delete);
    printTree(root);
    printf("\n");
    
    deleteTree(root); // видалення всього дерева
    
    return 0;
}

