#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Функції для роботи з бінарним деревом
struct TreeNode* create_node(int value);
struct TreeNode* insert(struct TreeNode* root, int value);
struct TreeNode* minValueNode(struct TreeNode* node);
struct TreeNode* deleteNode(struct TreeNode* root, int key);
int search(struct TreeNode* root, int key);
void inorder_traversal(struct TreeNode* root);

#endif

