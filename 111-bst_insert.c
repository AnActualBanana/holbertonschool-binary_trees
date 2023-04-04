#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *node, *current;

    if (!tree)
        return (NULL);

    if (!(*tree))
    {
        node = binary_tree_node(NULL, value);
        if (!node)
            return (NULL);
        *tree = node;
        return (node);
    }

    current = *tree;
    while (current)
    {
        if (value == current->n)
            return (NULL);

        if (value < current->n)
        {
            if (!current->left)
            {
                node = binary_tree_node(current, value);
                if (!node)
                    return (NULL);
                current->left = node;
                return (node);
            }
            current = current->left;
        }
        else
        {
            if (!current->right)
            {
                node = binary_tree_node(current, value);
                if (!node)
                    return (NULL);
                current->right = node;
                return (node);
            }
            current = current->right;
        }
    }
    return (NULL);
}
