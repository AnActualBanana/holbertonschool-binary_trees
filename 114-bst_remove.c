#include "binary_trees.h"
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *successor = root->right;
    root->n = successor->n;
    root->right = bst_remove(root->right, successor->n);

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


    while (successor->left != NULL) {
        successor = successor->left;
    }
    
    return root;
}
