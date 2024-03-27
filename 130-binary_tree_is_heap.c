#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * is_max_heap - Checks if a binary tree is a max heap.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 **/
int is_max_heap(const binary_tree_t *tree)
{
	int left_check = 1, right_check = 1;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL)
	{
		if (tree->n <= tree->left->n)
			return (0);
		left_check = is_max_heap(tree->left);
	}
	if (tree->right != NULL)
	{
		if (tree->n <= tree->right->n)
			return (0);
		right_check = is_max_heap(tree->right);
	}

	return (left_check && right_check);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_complete;

	if (tree == NULL)
		return (0);

	is_complete = binary_tree_is_complete(tree);
	if (!is_complete)
		return (0);

	return (is_max_heap(tree));
}
