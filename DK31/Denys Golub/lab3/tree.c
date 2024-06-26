#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *initialize_tree() {
    return NULL;
}

void destroy_tree(Node *root) {
    if (root != NULL) {
        destroy_tree(root->left_child);
        destroy_tree(root->right_child);
        free(root);
    }
}

void add_node(Node **root, int value) {
    if (*root == NULL) {
        *root = (Node *) malloc(sizeof(Node));
        (*root)->value = value;
        (*root)->left_child = NULL;
        (*root)->right_child = NULL;
    } else if (value < (*root)->value) {
        add_node(&(*root)->left_child, value);
    } else {
        add_node(&(*root)->right_child, value);
    }
}

void remove_node(Node **root, int value) {
    if (*root != NULL) {
        if (value < (*root)->value) {
            remove_node(&(*root)->left_child, value);
        } else if (value > (*root)->value) {
            remove_node(&(*root)->right_child, value);
        } else {
            if ((*root)->left_child == NULL) {
                Node *temp = (*root)->right_child;
                free(*root);
                *root = temp;
            } else if ((*root)->right_child == NULL) {
                Node *temp = (*root)->left_child;
                free(*root);
                *root = temp;
            } else {
                Node *temp = (*root)->right_child;
                while (temp->left_child != NULL) {
                    temp = temp->left_child;
                }
                (*root)->value = temp->value;
                remove_node(&(*root)->right_child, temp->value);
            }
        }
    }
}

Node *find_node(Node *root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return find_node(root->left_child, value);
    }
    return find_node(root->right_child, value);
}

void display_tree(Node *root) {
    if (root != NULL) {
        printf("%d ", root->value);
        display_tree(root->left_child);
        display_tree(root->right_child);
    }
}

void display_tree_reverse(Node *root) {
    if (root != NULL) {
        display_tree_reverse(root->left_child);
        display_tree_reverse(root->right_child);
        printf("%d ", root->value);
    }
}

void interact_with_users(Node **root) {
    int choice, value;
    do {
        printf("\nBinary Tree Operations\n");
        printf("1. Add Node\n");
        printf("2. Remove Node\n");
        printf("3. Find Node\n");
        printf("4. Display Tree\n");
        printf("5. Display Tree (Reverse)\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to add: ");
                scanf_s("%d", &value);
                add_node(root, value);
                break;
            case 2:
                printf("\nEnter value to remove: ");
                scanf_s("%d", &value);
                remove_node(root, value);
                break;
            case 3:
                printf("\nEnter value to find: ");
                scanf_s("%d", &value);
                Node *node = find_node(*root, value);
                if (node == NULL) {
                    printf("%d not found in tree.\n", value);
                } else {
                    printf("%d found in tree.\n", value);
                }
                break;
            case 4:
                printf("\nTree: ");
                display_tree(*root);
                printf("\n");
                break;
            case 5:
                printf("\nTree (Reverse): ");
                display_tree_reverse(*root);
                printf("\n");
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 6);
}
