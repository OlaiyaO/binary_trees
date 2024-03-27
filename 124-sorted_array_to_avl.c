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

	size_t pivot = (size / 2);

	pivot = (size % 2 == 0) ? pivot - 1 : pivot;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[pivot]);
		create_avl_tree(&((*node)->left), array, pivot, 1);
		create_avl_tree(&((*node)->left), array + pivot + 1,
				(size - 1 - pivot), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[pivot]);
		create_avl_tree(&((*node)->right), array, pivot, 1);
		create_avl_tree(&((*node)->right), array + pivot + 1,
				(size - 1 - pivot), 2);
	}
}

/**
 * sorted_array_to_avl - Constructs an AVL tree from a sorted array.
 *
 * @array: Input array of integers.
 * @size: Size of the array.
 * Return: Pointer to the current_node of the AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *current_node = NULL;

	if (size == 0)
		return (NULL);

	size_t pivot = (size / 2);

	pivot = (size % 2 == 0) ? pivot - 1 : pivot;

	current_node = binary_tree_node(current_node, array[pivot]);
	create_avl_tree(&current_node, array, pivot, 1);
	create_avl_tree(&current_node, array + pivot + 1, (size - 1 - pivot), 2);

	return (current_node);
}
