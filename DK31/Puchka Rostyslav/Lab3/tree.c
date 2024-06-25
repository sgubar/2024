#include "tree.h"
#include <stdlib.h>

void destroyNode(CharNode *aNode);
CharNode *createCharNodeWithValue(char value);
CharNode *getSuccessor(CharTree *tree, CharNode *toDelete);

CharTree *createCharTree() {
  CharTree *tree = (CharTree *)malloc(sizeof(CharTree));

  if (NULL != tree) {
    tree->root = NULL;
    tree->count = 0;
  }

  return tree;
}

void destroyCharTree(CharTree *tree) {
  if (NULL != tree) {
    destroyNode(tree->root);
    free(tree);
  }
}

void insertCharValueToTree(CharTree *tree, char value) {
  if (NULL == tree) {
    return;
  }

  CharNode *newNode = createCharNodeWithValue(value);
  if (NULL == newNode) {
    return;
  }

  // if tree empty
  if (NULL == tree->root) {
    tree->root = newNode;
    tree->count++;
  } else {
    CharNode *currentNode = tree->root;
    CharNode *parentNode = NULL;

    // search for free place for new node
    while (1) {
      parentNode = currentNode;

      if (value < currentNode->value) {
        // if value smaller then value of node, go left branch
        currentNode = currentNode->leftChild;
        if (NULL == currentNode) {
          // currentNode don't exist, place found
          parentNode->leftChild = newNode;
          break;
        }
      } else {
        // if value greater then value of node, go left branch
        currentNode = currentNode->rightChild;
        if (NULL == currentNode) {
          // currentNode don't exist, place found
          parentNode->rightChild = newNode;
          break;
        }
      }
    }

    tree->count++;
  }
}

void deleteNodeWithValue(CharTree *tree, char value) {
  // return if tree don't exist or tree is empty
  if (NULL == tree || NULL == tree->root) {
    return;
  }

  CharNode *current = tree->root;
  CharNode *parent = tree->root;

  // find node to be deleted
  while (value != current->value) {
    parent = current;
    if (value < current->value) {
      current = current->leftChild;
    } else {
      current = current->rightChild;
    }

    // return if node with this value don't exist
    if (NULL == current) {
      return;
    }
  }

  if (NULL == current->leftChild && NULL == current->rightChild) {
    // node is leaf
    if (tree->root == current) {
      tree->root = NULL;
    } else if (parent->leftChild == current) {
      parent->leftChild = NULL;
    } else {
      parent->rightChild = NULL;
    }
  } else if (NULL == current->rightChild) {
    // node has only left branch
    if (tree->root == current) {
      tree->root = current->leftChild;
    } else if (parent->leftChild == current) {
      parent->leftChild = current->leftChild;
    } else {
      parent->rightChild = current->leftChild;
    }
  } else if (NULL == current->leftChild) {
    // node has only right branch
    if (tree->root == current) {
      tree->root = current->rightChild;
    } else if (parent->rightChild == current) {
      parent->rightChild = current->rightChild;
    } else {
      parent->leftChild = current->rightChild;
    }
  } else {
    // node has both branch
    CharNode *successor = getSuccessor(tree, current);
    if (tree->root == current) {
      tree->root = successor;
    } else if (parent->leftChild == current) {
      parent->leftChild = successor;
    } else {
      parent->rightChild = successor;
    }
  }

  current->leftChild = NULL;
  current->rightChild = NULL;
  destroyNode(current);
}

void printTree(CharTree *tree) {
  if (NULL == tree) {
    printf("Tree pointer is NULL!\n");
    return;
  }
  printNode(tree->root);
}

void printNode(CharNode *node) {
  if (node == NULL) {
    return;
  }

  printNode(node->leftChild);
  printNode(node->rightChild);
  printf("%c ", node->value);
}

void destroyNode(CharNode *node) {
  if (NULL != node) {
    destroyNode(node->leftChild);
    destroyNode(node->rightChild);

    free(node);
  }
}

CharNode *createCharNodeWithValue(char value) {
  CharNode *newNode = (CharNode *)malloc(sizeof(CharNode));

  if (NULL != newNode) {
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->value = value;
  }

  return newNode;
}

CharNode *getSuccessor(CharTree *tree, CharNode *toDeleteNode) {
  CharNode *successParent = toDeleteNode;
  CharNode *successor = toDeleteNode;
  CharNode *current = toDeleteNode->rightChild;

  while (NULL != current) {
    successParent = successor;
    successor = current;
    current = current->leftChild;
  }

  if (successor != toDeleteNode->rightChild) {
    successParent->leftChild = successor->rightChild;
    successor->rightChild = toDeleteNode->rightChild;
  }

  successor->leftChild = toDeleteNode->leftChild;

  return successor;
}
