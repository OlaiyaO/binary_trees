#include "binary_trees.h"
#include "limits.h"

/**
 * is_valid_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min_value: Smallest value allowed for the current subtree.
 * @max_value: Largest value allowed for the current subtree.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_valid_bst(const binary_tree_t *tree, int min_value, int max_value)
{
	if (tree)
	{
		if (tree->n < min_value || tree->n > max_value)
			return (0);
		return (is_valid_bst(tree->left, min_value, tree->n - 1) &&
			is_valid_bst(tree->right, tree->n + 1, max_value));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_valid_bst(tree, INT_MIN, INT_MAX));
}
