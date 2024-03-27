#include "binary_trees.h"

/**
 * create_avl_tree - Recursively creates an AVL tree.
 *
 * @node: Pointer to the current node.
 * @array: Input array of integers.
 * @size: Size of the array.
 * @mode: 1 to add to the left, 2 to add to the right.
 *
 * Return: No return value.
 */
void create_avl_tree(avl_t **node, int *array, size_t size, int mode)
{
	if (size == 0)
		return;

	size_t middle = (size / 2);

	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		create_avl_tree(&((*node)->left), array, middle, 1);
		create_avl_tree(&((*node)->left), array + middle + 1,
				(size - 1 - middle), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		create_avl_tree(&((*node)->right), array, middle, 1);
		create_avl_tree(&((*node)->right), array + middle + 1,
				(size - 1 - middle), 2);
	}
}

/**
 * sorted_array_to_avl - Constructs an AVL tree from a sorted array.
 *
 * @array: Input array of integers.
 * @size: Size of the array.
 * Return: Pointer to the root of the AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (size == 0)
		return (NULL);

	size_t middle = (size / 2);

	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(root, array[middle]);
	create_avl_tree(&root, array, middle, 1);
	create_avl_tree(&root, array + middle + 1, (size - 1 - middle), 2);

	return (root);
}
