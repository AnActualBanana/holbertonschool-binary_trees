#include "binary_trees.h"

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = NULL, *old_right = NULL;

    /* If parent is NULL, return NULL */
    if (!parent)
        return (NULL);

    /* If parent already has a right child, save it for later */
    if (parent->right)
        old_right = parent->right;

    /* Create the new node */
    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);

    /* Insert the new node as the right child of parent */
    parent->right = new_node;
    new_node->parent = parent;

    /* If parent had a right child, set it as the right child of the new node */
    if (old_right)
    {
        new_node->right = old_right;
        old_right->parent = new_node;
    }

    return (new_node);
}
