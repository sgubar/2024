#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

double getDoubleFromUser(const char *prompt) {
    double value;
    char input[100];
    int valid = 0;

    while (!valid) {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) != NULL) {
            char *endptr;
            value = strtod(input, &endptr);
            if (endptr != input && (*endptr == '\n' || *endptr == '\0')) {
                valid = 1;
            } else {
                printf("Invalid input. Please enter a valid number.\n");
            }
        }
    }

    return value;
}

void menu() {
    printf("Binary Tree Operations:\n");
    printf("1. Create tree with elements\n");
    printf("2. Insert element\n");
    printf("3. Delete element\n");
    printf("4. Search element\n");
    printf("5. Print tree\n");
    printf("6. Delete entire tree\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void createTreeWithElements(Tree *tree) {
    int count;
    printf("Enter the number of elements to insert: ");
    while (scanf("%d", &count) != 1 || count < 0) {
        while (getchar() != '\n'); // clear the buffer
        printf("Invalid input. Please enter a non-negative integer.\n");
    }
    while (getchar() != '\n'); // clear the buffer

    for (int i = 0; i < count; i++) {
        double value = getDoubleFromUser("Enter value: ");
        insertElement(tree, value);
    }
}

void deleteEntireTree(Tree **tree) {
    if (*tree != NULL) {
        destroyTree(*tree);
        *tree = createTree();
        printf("Tree has been deleted and recreated.\n");
    } else {
        printf("Tree does not exist.\n");
    }
}

int main() {
    Tree *tree = createTree();
    int choice;
    double value;

    while (1) {
        menu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear the buffer
            printf("Invalid choice. Please enter a number between 1 and 7.\n");
            continue;
        }

        while (getchar() != '\n'); // clear the buffer after reading choice

        switch (choice) {
            case 1:
                createTreeWithElements(tree);
                break;
            case 2:
                value = getDoubleFromUser("Enter the value to insert: ");
                insertElement(tree, value);
                break;
            case 3:
                value = getDoubleFromUser("Enter the value to delete: ");
                deleteElement(tree, value);
                break;
            case 4:
                value = getDoubleFromUser("Enter the value to search: ");
                TreeNode *node = searchElement(tree, value);
                if (node != NULL) {
                    printf("Element %lf found in the tree.\n", node->num);
                } else {
                    printf("Element %lf not found in the tree.\n", value);
                }
                break;
            case 5:
                printf("Tree elements (post-order): ");
                printTree(tree);
                break;
            case 6:
                deleteEntireTree(&tree);
                break;
            case 7:
                destroyTree(tree);
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}
