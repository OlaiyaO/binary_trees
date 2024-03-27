#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: Pointer to the root node of the BST to search.
 * @value: The value to be searched for in the BST.
 *
 * Return: Returns a pointer to the node containing the value if
 *	tree and value is found otherwise returns NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
