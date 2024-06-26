#ifndef TREE_H
#define TREE_H

typedef struct node {
    int value;
    struct node* left_child;
    struct node* right_child;
} Node;

Node* initialize_tree();

void destroy_tree(Node* root);

void add_node(Node** root, int value);

void remove_node(Node** root, int value);

Node* find_node(Node* root, int value);

void display_tree(Node* root);

void display_tree_reverse(Node* root);

void interact_with_users(Node** root);

#endif