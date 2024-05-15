//
// Created by Nazar Pechkovsky on 13.05.2024.
//

#ifndef CODE_TREE_H
#define CODE_TREE_H

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree {
    Node *root;
    int size;
} Tree;


Node *createNode(int value);
Tree *createTree();
void addNode(Tree *tree, int value);
void printTree(Tree *tree);
void printNodes(Node *node);
void deleteNode(Tree *tree, int value);
int searchNode(Node *node, int value);
void deleteNodes(Node *node);

#endif //CODE_TREE_H
