#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    Node* root = initialize_tree();

    printf("Binary Tree Operations\n");

    int choice, value;

    interact_with_users(&root);

    destroy_tree(root);

    return 0;
}