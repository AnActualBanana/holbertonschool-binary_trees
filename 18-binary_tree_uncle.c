#include "binary_trees.h"
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    binary_tree_t *grandparent = node->parent->parent;

    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return NULL;

    if (grandparent->left == node->parent)
        return grandparent->right;
    else if (grandparent->right == node->parent)
        return grandparent->left;
    else
        return NULL;
}
