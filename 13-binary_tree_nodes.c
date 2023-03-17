#include "binary_trees.h"

size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t nodes_count = 0;
    if (tree == NULL)
        return 0;

    if (tree->left != NULL || tree->right != NULL)
        nodes_count++;

    nodes_count += binary_tree_nodes(tree->left);
    nodes_count += binary_tree_nodes(tree->right);

    return nodes_count;
}
