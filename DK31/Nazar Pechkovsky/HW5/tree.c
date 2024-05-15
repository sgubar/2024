//
// Created by Nazar Pechkovsky on 13.05.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//Створення вузла
Node *createNode(int value)
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

void addNode(Tree *tree,int value)
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

//Виведення вузла зворотнім методом
void printNodes(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printNodes(node->left);
    printNodes(node->right);
    printf("%d, ", node->value);
}

//Пошук вузла
int searchNode(Node *node, int value)
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
void deleteNode(Tree *tree, int value)
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
        }

    }

    if (current == NULL)
    {
        printf("Value not found\n");
        return;
    }

    printf("Value %d is deleted\n", current->value);


    if(current->left == NULL && current->right == NULL)
    {
        if (parent == NULL)
        {
            tree->root = NULL;
        }
        else if (parent->left == current)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        free(current);
    }

    else if(current->left != NULL && current->right != NULL)
    {
        Node *localParent = current;
        Node *temp = current->right;
        while(temp->left != NULL)
        {
            localParent = temp;
            temp = temp->left;
        }
        current->value = temp->value;

        if (localParent->left == temp) //Якщо є лівий нащадок при переході на правого нащадка
        {
            localParent->left = temp->right;
        } else //Якщо немає лівого нащадка при переході на правого нащадка
        {
            localParent->right = temp->right;
        }

        free(temp);
        return;
    }

    else {
        Node *child;
        if (current->left != NULL) {
            child = current->left;
        } else {
            child = current->right;
        }

        if (parent == NULL)
        {
            tree->root = child;
        }
        else if (parent->left == current)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        free(current);
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