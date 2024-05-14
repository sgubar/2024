//
// Created by Nazar Pechkovsky on 13.05.2024.
//

#ifndef CODE_TREE_H
#define CODE_TREE_H

typedef struct Node {
    char value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree {
    Node *root;
    int size;
} Tree;


Node *createNode(char value);
Tree *createTree();
void addNode(Tree *tree, char value);
void printTree(Tree *tree);
void printNodes(Node *node);
void deleteNode(Tree *tree, char value);
int searchNode(Node *node, char value);
void deleteTree(Tree *tree);
void deleteNodes(Node *node);

#endif //CODE_TREE_H
