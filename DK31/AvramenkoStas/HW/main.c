#include <stdio.h>
#include "binary_tree.h"

int main() {
    struct TreeNode* root = NULL;
    int value, num_elements;

    // Запит користувача про кількість елементів для вставки у дерево
    printf("Enter the number of elements to insert into the binary tree: ");
    scanf("%d", &num_elements);

    // Вставка елементів у дерево
    printf("Enter %d elements to insert into the binary tree:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Виведення дерева
    printf("Binary Tree Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Пошук елемента
    int search_key;
    printf("Enter the element to search: ");
    scanf("%d", &search_key);
    if (search(root, search_key))
        printf("%d is found in the tree.\n", search_key);
    else
        printf("%d is not found in the tree.\n", search_key);

    // Видалення елемента
    int delete_key;
    printf("Enter the element to delete: ");
    scanf("%d", &delete_key);
    root = deleteNode(root, delete_key);
    printf("Binary Tree Inorder Traversal after deletion: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}


