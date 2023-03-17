#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node, *old_left;

    if (parent == NULL)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    old_left = parent->left;
    parent->left = new_node;
    new_node->left = old_left;

    if (old_left != NULL)
        old_left->parent = new_node;

    return (new_node);
}
