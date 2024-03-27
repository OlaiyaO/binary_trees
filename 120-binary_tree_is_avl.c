#include "binary_trees.h"
#include "limits.h"

size_t calculate_height(const binary_tree_t *node);
int is_avl_util(const binary_tree_t *tree, int min_val, int max_val);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * calculate_height - Calculates the height of a binary tree.
 * @node: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
size_t calculate_height(const binary_tree_t *node)
{
	if (node)
	{
		size_t left_height = node->left ? 1 + calculate_height(node->left) : 1;
		size_t right_height = node->right ? 1 + calculate_height(node->right) : 1;

		return (left_height > right_height ? left_height : right_height);
	}
	return (0);
}

/**
 * is_avl_util - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 * @min_val: The minimum value allowed for the current subtree.
 * @max_val: The maximum value allowed for the current subtree.
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0.
 */
int is_avl_util(const binary_tree_t *tree, int min_val, int max_val)
{
	size_t left_height, right_height, height_diff;

	if (tree)
	{
		if (tree->n < min_val || tree->n > max_val)
			return (0);
		left_height = calculate_height(tree->left);
		right_height = calculate_height(tree->right);
		height_diff = (left_height > right_height) ?
			left_height - right_height :
			right_height - left_height;
		if (height_diff > 1)
			return (0);
		return (is_avl_util(tree->left, min_val, tree->n - 1) &&
				is_avl_util(tree->right, tree->n + 1, max_val));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree)
		return (is_avl_util(tree, INT_MIN, INT_MAX));
	return (0);
}

