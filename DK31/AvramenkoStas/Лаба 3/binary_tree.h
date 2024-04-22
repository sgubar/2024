#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Структура для вузла бінарного дерева
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Прототипи функцій
struct Node* createNode(int key);
struct Node* insert(struct Node* root, int key);
void printTree(struct Node* root);
struct Node* search(struct Node* root, int key);
struct Node* deleteNode(struct Node* root, int key);
void deleteTree(struct Node* root);

#endif

