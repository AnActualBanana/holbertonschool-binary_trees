#include "binary_trees.h"
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL) {
        return NULL;
    }

    if (value < root->n) {
        root->left = bst_remove(root->left, value);
        return root;
    }

    if (value > root->n) {
        root->right = bst_remove(root->right, value);
        return root;
    }

    // value == root->n: this is the node to remove

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    if (root->left == NULL) {
        bst_t *right = root->right;
        free(root);
        return right;
    }

    if (root->right == NULL) {
        bst_t *left = root->left;
        free(root);
        return left;
    }

    // the node has two children: find the in-order successor
    bst_t *successor = root->right;
    while (successor->left != NULL) {
        successor = successor->left;
    }
    root->n = successor->n;
    root->right = bst_remove(root->right, successor->n);
    return root;
}
