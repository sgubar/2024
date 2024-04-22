#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

// Функція для створення нового вузла з заданим ключем
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Функція для вставки нового вузла в бінарне дерево
struct Node* insert(struct Node* root, int key) {
    // Якщо дерево порожнє, створюємо новий вузол
    if (root == NULL) return createNode(key);
    
    // Якщо ключ менший за корінь, рекурсивно вставляємо його вліво
    if (key < root->data)
        root->left = insert(root->left, key);
    // Якщо ключ більший за корінь, рекурсивно вставляємо його вправо
    else if (key > root->data)
        root->right = insert(root->right, key);
    
    // Повертаємо корінь після вставки
    return root;
}

// Функція для виведення бінарного дерева (ін-ордер обхід)
void printTree(struct Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

// Функція для пошуку елементу в бінарному дереві
struct Node* search(struct Node* root, int key) {
    // Якщо дерево порожнє або ключ знаходиться в корені, повертаємо корінь
    if (root == NULL || root->data == key)
        return root;
    
    // Якщо ключ менший за корінь, шукаємо вліво
    if (root->data > key)
        return search(root->left, key);
    
    // Якщо ключ більший за корінь, шукаємо вправо
    return search(root->right, key);
}

// Функція для видалення елементу з бінарного дерева
struct Node* deleteNode(struct Node* root, int key) {
    // Якщо дерево порожнє, повертаємо NULL
    if (root == NULL) return root;
    
    // Знаходимо вузол з ключем key
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Вузол з одним або без дітей
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Вузол з двома дітьми: замінюємо вузол мінімальним ключем у правому піддереві
        struct Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        
        // Копіюємо ключ мінімального вузла у корінь
        root->data = temp->data;
        
        // Видаляємо мінімальний вузол у правому піддереві
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Функція для видалення всього дерева
void deleteTree(struct Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

