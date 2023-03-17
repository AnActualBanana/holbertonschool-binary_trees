#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height, i, nodes;

    if (!tree)
        return (0);

    height = binary_tree_height(tree);

    nodes = 0;
    for (i = 0; i <= height; i++)
        nodes += 1 << i;

    return (nodes == binary_tree_size(tree));
}
