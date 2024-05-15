#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

//Програма розставляє елементи в дереві відповідно до їх значень

int main(void) {
    int temp = 0;

    Tree *MyTree = createTree();
    addNode(MyTree, 54);
    addNode(MyTree, -4);
    addNode(MyTree, 2);
    addNode(MyTree, 652);
    addNode(MyTree, 30);
    addNode(MyTree, -52453);
    addNode(MyTree, 5932);
    addNode(MyTree, 6455);
    addNode(MyTree, 0);
    addNode(MyTree, 23);
    addNode(MyTree, 11);

    printTree(MyTree);
    deleteNode(MyTree, 2);
    printTree(MyTree);

    temp = searchNode(MyTree->root, 30);
    if (temp == 0) {
        printf("Value not found in the tree\n");
    } else {
        printf("Value found in the tree\n");
    }

    printf("The size of the tree is: %d\n", MyTree->size);
}
