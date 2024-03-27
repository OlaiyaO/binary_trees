#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t index, compared_index;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (compared_index = 0; compared_index < index; compared_index++)
		{
			if (array[compared_index] == array[index])
				break;
		}
		if (compared_index == index)
		{
			if (bst_insert(&root, array[index]) == NULL)
				return (NULL);
		}
	}

	return (root);
}
