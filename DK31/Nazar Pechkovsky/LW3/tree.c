//
// Created by Nazar Pechkovsky on 13.05.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void printNodes(Node *node);

//Створення вузла
Node *createNode(char value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL)
    {
        return NULL;
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Створення дерева
Tree *createTree()
{
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    if (tree == NULL)
    {
        return NULL;
    }

    tree->root = NULL;
    tree->size = 0;
    return tree;
}

//Додавання вузла
void addNode(Tree *tree, char value)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->root == NULL)
    {
        tree->root = createNode(value);
        tree->size++;
    } else
    {
        Node *current = tree->root;
        while (1)
        {
            if (value < current->value)
            {
                if (current->left == NULL)
                {
                    current->left = createNode(value);
                    tree->size++;
                    break;
                } else
                {
                    current = current->left;
                }
            } else if (value > current->value)
            {
                if (current->right == NULL) {
                    current->right = createNode(value);
                    tree->size++;
                    break;
                } else {
                    current = current->right;
                }
            } else if(value == current->value)
            {
                printf("Value already exists in the tree\n");
                break;
            }
        }
    }
}

//Виведення дерева
void printTree(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->root == NULL)
    {
        printf("Tree is empty\n");
    } else
    {
        printf("Tree: ");
        printNodes(tree->root);
        printf("\n");
    }
}

//Виведення вузла
void printNodes(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%c, ", node->value);
    printNodes(node->left);
    printNodes(node->right);
}

//Пошук вузла
int searchNode(Node *node, char value)
{
    if (node == NULL)
    {
        return 0;
    }

    if (node->value == value)
    {
        return 1;
    }

    if (value < node->value)
    {
        return searchNode(node->left, value);
    } else
    {
        return searchNode(node->right, value);
    }
}

//Видалення вузла
void deleteNode(Tree *tree, char value)
{
    if (tree == NULL)
    {
        return;
    }

    Node *current = tree->root;
    Node *parent = NULL;
    while (current != NULL && current->value != value)
    {
        parent = current;
        if (value < current->value)
        {
            current = current->left;
        } else if (value > current->value)
        {
            current = current->right;
        } else if (value == current->value)
        {
            current = tree->root;
        }
    }

    if (current == NULL)
    {
        printf("Value not found\n");
        return;
    }

    printf("Value %c is deleted\n", current->value);


    if(current->left == NULL && current->right == NULL)
    {
        if(parent->left == current)
        {
            free(current);
            parent->left = NULL;
        } else
        {
            free(current);
            parent->right = NULL;
        }
        return;
    }

    if(current->left != NULL && current->right != NULL)
    {
        Node *temp = current->right;
        while(temp->left != NULL)
        {
            parent = temp;
            temp = temp->left;
        }
        current->value = temp->value;
        parent->left = NULL;
        free(temp);
        return;
    }

    if(current->left == NULL || current->right == NULL)
    {
        if(current->left != NULL && current->right == NULL)
        {
            current->value = current->left->value;
            free(current->left);
            current->left = NULL;
            return;
        } else if(current->left == NULL && current->right != NULL)
        {
            current->value = current->right->value;
            free(current->right);
            current->right = NULL;
            return;
        }
    }
}

//Видалення всіх вузлів
void deleteNodes(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    deleteNodes(node->left);
    deleteNodes(node->right);
    free(node);
}

//Видалення дерева
void deleteTree(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->root == NULL)
    {
        free(tree);
        return;
    }

    deleteNodes(tree->root);
    free(tree);
}