#include "binary_trees.h"

/**
 * array_to_avl - Constructs an AVL tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in @array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL
 *	on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index_outer, index_inner;

	if (array == NULL)
		return (NULL);

	for (index_outer = 0; index_outer < size; index_outer++)
	{
		for (index_inner = 0; index_inner < index_outer; index_inner++)
		{
			if (array[index_inner] == array[index_outer])
				break;
		}
		if (index_inner == index_outer)
		{
			if (avl_insert(&tree, array[index_outer]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
