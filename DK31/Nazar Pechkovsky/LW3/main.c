#include <stdio.h>
#include <string.h>
#include "tree.h"

//Програма розставляє елементи в дереві відповідно до їх значень в таблиці ASCII

int main(void) {
    char value;
    int temp = 0;
    char command[10] = "";
    char buffer[10] = "";

    Tree *MyTree = createTree();
    printf("What do you want:\n"
           "add - for adding a new node\n"
           "print - for printing the tree\n"
           "escape - for exiting the program\n"
           "delete - for deleting the node\n"
           "search - for searching the node\n"
           "size - for getting the size of the tree\n"
           "Only the first character is added to the tree\n");

    while (1)
    {
        printf("Enter command: ");
        scanf("%9s", command);

        //При введенні add користувач може вводити символи для додавання в дерево
        if (strcmp(command, "add") == 0)
        {
            printf("Enter the char you want to add to the tree or 'exit' for exiting the command:");
            while (scanf("%9s", buffer) == 1 && strcmp(buffer, "exit") != 0)
            {
                value = buffer[0];
                addNode(MyTree, value);
                printf("Enter another char to add or 'exit' to exit: ");
            }
        }

        //При введенні print користувач може вивести дерево на екран
        else if (strcmp(command, "print") == 0)
        {
            printTree(MyTree);
        }

        //При введенні delete користувач може видалити вузол з дерева
        else if (strcmp(command, "delete") == 0)
        {
            printf("Enter the char you want to delete from the tree or 'exit' for exiting the command:");
            while (scanf("%9s", buffer) == 1 && strcmp(buffer, "exit") != 0)
            {
                value = buffer[0];
                deleteNode(MyTree, value);
                printf("Enter another char to delete or 'exit' to exit: ");
            }
        }

        //При введенні search користувач може знайти вузол в дереві
        else if (strcmp(command, "search") == 0)
        {
            printf("Enter the char you want to search in the tree or 'exit' for exiting the command:");
            while (scanf("%9s", buffer) == 1 && strcmp(buffer, "exit") != 0) {
                value = buffer[0];
                temp = searchNode(MyTree->root, value);
                if (temp == 0) {
                    printf("Value not found in the tree\n");
                } else {
                    printf("Value found in the tree\n");
                }
                temp = 0;
                printf("Enter another char to delete or 'exit' to exit: ");
            }
        }

        //При введенні size користувач може дізнатися розмір дерева
        else if (strcmp(command, "size") == 0)
        {
            printf("The size of the tree is: %d\n", MyTree->size);
        }

        //При введенні escape програма завершує роботу
        else if (strcmp(command, "escape") == 0)
        {
            deleteTree(MyTree);
            return 0;
        }

        //Якщо користувач ввів невідому команду, програма виведе повідомлення про помилку і запустить цикл знову
        else
        {
            printf("Invalid command\n");
        }
    }
}
