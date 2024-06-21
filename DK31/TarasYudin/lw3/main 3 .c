

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Структура вузла дерева
struct treeElement {
    int data;
    struct treeElement* left;
    struct treeElement* right;
};

// Функція для створення нового вузла
struct treeElement* createTreeElement(int data) {
    struct treeElement* newTreeElement = (struct treeElement*)malloc(sizeof(struct treeElement));
    newTreeElement->data = data;
    newTreeElement->left = NULL;
    newTreeElement->right = NULL;
    return newTreeElement;
}

// Функція для вставки нового елементу в дерево
struct treeElement* insert(struct treeElement* treeElement, int data) {
    if (treeElement == NULL) {
        return createTreeElement(data);
    }
    if (data < treeElement->data) {
        treeElement->left = insert(treeElement->left, data);
    }
    else if (data > treeElement->data) {
        treeElement->right = insert(treeElement->right, data);
    }
    return treeElement;
}

// Функція для пошуку мінімального значення в дереві
struct treeElement* minValueTree(struct treeElement* tree) {
    struct treeElement* current = tree;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Функція для видалення елементу з дерева
struct treeElement* deleteTreeElement(struct treeElement* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = deleteTreeElement(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteTreeElement(root->right, data);
    }
    else {
        if (root->left == NULL) {
            struct treeElement* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct treeElement* temp = root->left;
            free(root);
            return temp;
        }
        struct treeElement* temp = minValueTree(root->right);
        root->data = temp->data;
        root->right = deleteTreeElement(root->right, temp->data);
    }
    return root;
}

// Функція для пошуку елементу в дереві
struct treeElement* searchTreeElement(struct treeElement* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data < data) {
        return searchTreeElement(root->right, data);
    }
    return searchTreeElement(root->left, data);
}

// Функція для зворотнього обходу дерева
void reverseInOrder(struct treeElement* root) {
    if (root != NULL) {
        reverseInOrder(root->right);
        printf("%d ", root->data);
        reverseInOrder(root->left);
    }
}

// Функція для очищення дерева
void clearTree(struct treeElement* root) {
    if (root != NULL) {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
    }
}

// Функція для введення цілих чисел з перевіркою
int inputInt(const char* prompt) {
    int value;
    char buffer[100];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            char* endptr;
            value = strtol(buffer, &endptr, 10);
            if (endptr != buffer && *endptr == '\n') {
                break;
            }
        }
        printf("Неправильний формат. Будь ласка, введіть ціле число.\n");
    }
    return value;
}

int main() {


    struct treeElement* root = NULL;
    int choice, data;

    do {
        printf("\nМеню:\n");
        printf("1. Додати елемент\n");
        printf("2. Видалити елемент\n");
        printf("3. Знайти елемент\n");
        printf("4. Друк дерева (зворотній обхід)\n");
        printf("5. Вийти\n");
        choice = inputInt("Ваш вибір: ");
        switch (choice) {
                case 1:
                    data = inputInt("Введіть ціле число для додавання: ");
                    root = insert(root, data);
                    break;
                case 2:
                    data = inputInt("Введіть ціле число для видалення: ");
                    root = deleteTreeElement(root, data);
                    break;
                case 3:
                    data = inputInt("Введіть ціле число для пошуку: ");
                    struct treeElement* found = searchTreeElement(root, data);
                    if (found != NULL) {
                        printf("Елемент %d знайдено в дереві.\n", data);
                    }
                    else {
                        printf("Елемент %d не знайдено в дереві.\n", data);
                    }
                    break;
                case 4:
                    printf("Дерево (зворотній обхід): ");
                    reverseInOrder(root);
                    printf("\n");
                    break;
                case 5:
                    clearTree(root);
                    printf("Вихід з програми.\n");
                    break;
                default:
                    printf("Невірний вибір. Спробуйте ще раз.\n");
                }
            } while (choice != 5);

            return 0;
        }