#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Tree *createTree(void) {
    Tree *result = (Tree*) malloc(sizeof(Tree));
    if (result != NULL) {
        result->root = NULL;
        result->count = 0;
    }
    return result;
}

void destroyNode(TreeNode *currentNode) {
    if (currentNode != NULL) {
        destroyNode(currentNode->left);
        destroyNode(currentNode->right);
        free(currentNode);
    }
}

void destroyTree(Tree *tree) {
    if (tree != NULL) {
        destroyNode(tree->root);
        free(tree);
    }
}

signed char insertNode(TreeNode **current, VALTYPE num) {
    if (*current == NULL) {
        *current = (TreeNode*) malloc(sizeof(TreeNode));
        if (*current != NULL) {
            (*current)->num = num;
            (*current)->left = NULL;
            (*current)->right = NULL;
            return 1;
        }
        return 0;
    }

    if (num < (*current)->num) {
        return insertNode(&((*current)->left), num);
    } else if (num > (*current)->num) {
        return insertNode(&((*current)->right), num);
    }
    return 0;
}

void insertElement(Tree *tree, VALTYPE num) {
    if (tree != NULL) {
        tree->count += insertNode(&(tree->root), num);
    }
}

TreeNode **searchNode(TreeNode **current, VALTYPE num) {
    if (*current == NULL) {
        return NULL;
    }

    if (num < (*current)->num) {
        return searchNode(&((*current)->left), num);
    } else if (num > (*current)->num) {
        return searchNode(&((*current)->right), num);
    } else {
        return current;
    }
}

TreeNode* searchElement(Tree *tree, VALTYPE num) {
    if (tree == NULL) {
        return NULL;
    }

    TreeNode **res = searchNode(&(tree->root), num);
    return (res == NULL ? NULL : *res);
}

void deleteNode(TreeNode **currentPtr) {
    TreeNode *current = *currentPtr;

    if (current->left == NULL && current->right == NULL) {
        *currentPtr = NULL;
    } else if (current->left == NULL) {
        *currentPtr = current->right;
    } else if (current->right == NULL) {
        *currentPtr = current->left;
    } else {
        TreeNode **successorPtr = &(current->right);
        while ((*successorPtr)->left != NULL) {
            successorPtr = &((*successorPtr)->left);
        }
        current->num = (*successorPtr)->num;
        TreeNode *successor = *successorPtr;
        *successorPtr = (*successorPtr)->right;
        free(successor);
        return;
    }
    free(current);
}

void deleteElement(Tree *tree, VALTYPE num) {
    if (tree == NULL) {
        return;
    }

    TreeNode **currentPtr = searchNode(&(tree->root), num);
    if (currentPtr != NULL) {
        deleteNode(currentPtr);
        tree->count--;
    }
}

void printNode(TreeNode *node) {
    if (node != NULL) {
        printNode(node->left);
        printNode(node->right);
        printf("%lf ", node->num);
    }
}

void printTree(Tree *tree) {
    if (tree != NULL) {
        printNode(tree->root);
        printf("\n");
    } else {
        printf("(NULL)\n");
    }
}
