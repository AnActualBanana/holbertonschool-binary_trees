#include "binary_trees.h"

/**
 * check_bst - helper function to recursively check if a binary tree is a BST
 * @tree: pointer to the root node of the tree to check
 * @min: pointer to the minimum allowed value
 * @max: pointer to the maximum allowed value
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int check_bst(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
    if (!tree)
        return (1);

    if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
        return (0);

    return (check_bst(tree->left, min, tree) && check_bst(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (check_bst(tree, NULL, NULL));
}
